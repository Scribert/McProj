#include <iostream>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <pybind11/embed.h>
namespace py = pybind11;

#include "Plugins.hpp"

// A way to access a local variable in a function in which I can't choose the parameters of
Plugins* pluginsPtr = nullptr;

void mouseMoved(GLFWwindow* window, double xpos, double ypos) {
    if (pluginsPtr)
        pluginsPtr->run("mouseMoved", glm::vec2(xpos, ypos));
}

void mousePressedOrReleased(GLFWwindow* window, int button, int action, int mods) {
    if (pluginsPtr) {
        if (action == GLFW_PRESS)
            pluginsPtr->run("mousePressed", button);
        else if (action == GLFW_RELEASE)
            pluginsPtr->run("mouseReleased", button);
    }

}

void keyPressedOrReleased(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (pluginsPtr) {
        if (action == GLFW_PRESS)
            pluginsPtr->run("keyPressed", key);
        else if (action == GLFW_RELEASE)
            pluginsPtr->run("keyReleased", key);
    }
}

int main() {

    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create main window
    GLFWwindow* window = glfwCreateWindow(800, 600, "change later", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        std::cout << "Couldn't create a GLFW window.";
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Couldn't initialize GLAD";
        return -1;
    }

    py::scoped_interpreter pythonInterpreter;
    py::module_ os = py::module_::import("os");
    py::module_ sys = py::module_::import("sys");
    py::module_ editor = py::module_::import("editor");

    std::string path = os.attr("getcwd")().cast<std::string>();
    sys.attr("path").attr("append")(path + "\\plugins");

    Plugins plugins = Plugins();
    pluginsPtr = &plugins;

    glfwSetCursorPosCallback(window, mouseMoved);
    glfwSetMouseButtonCallback(window, mousePressedOrReleased);
    glfwSetKeyCallback(window, keyPressedOrReleased);

    plugins.loadAllPlugins();

    while (!glfwWindowShouldClose(window)) {

        plugins.run("everyFrame");

        glClearColor(0.471f, 0.655f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
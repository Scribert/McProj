#include <iostream>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <pybind11/embed.h>
namespace py = pybind11;

#include "events.hpp"
#include "Plugins.hpp"
#include "PressedList.hpp"
#include "Stopwatch.hpp"

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

    glfwSetCursorPosCallback(window, mouseMoved);
    glfwSetMouseButtonCallback(window, mouseButtonPressedOrReleased);
    glfwSetKeyCallback(window, keyPressedOrReleased);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Couldn't initialize GLAD";
        return -1;
    }

    // Start the interpreter and load builtin modules
    py::scoped_interpreter pythonInterpreter;
    py::module_ os = py::module_::import("os");
    py::module_ sys = py::module_::import("sys");
    py::module_ editor = py::module_::import("minecraft_editor");

    // Add attrs to minecraft_editor module
    editor.attr("pressedKeys") = PressedList(window, glfwGetKey);
    editor.attr("pressedMouseButtons") = PressedList(window, glfwGetMouseButton);

    // Add "\plugins" to the module search path
    std::string path = os.attr("getcwd")().cast<std::string>();
    sys.attr("path").attr("append")(path + "\\plugins");

    // Load all plugins
    Plugins::plugins.loadAllPlugins();

    Stopwatch frameStopwatch;

    while (!glfwWindowShouldClose(window)) {
        
        // Calculate deltaTime (seconds per frame)
        frameStopwatch.SaveTime();
        frameStopwatch.NewLap();

        // Call the function everyFrame in all modules with deltaTime as a parameter
        Plugins::plugins.run("everyFrame", frameStopwatch.SavedTime());

        glClearColor(0.471f, 0.655f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
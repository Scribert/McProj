#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Plugins.hpp"

void mouseMoved(GLFWwindow* window, double xpos, double ypos) {
    Plugins::plugins.run("mouseMoved", glm::vec2(xpos, ypos));
}

void mouseButtonPressedOrReleased(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS)
        Plugins::plugins.run("mouseButtonPressed", button, mods);
    else if (action == GLFW_RELEASE)
        Plugins::plugins.run("mouseButtonReleased", button, mods);
}

void keyPressedOrReleased(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS)
        Plugins::plugins.run("keyPressed", key, mods);
    else if (action == GLFW_RELEASE)
        Plugins::plugins.run("keyReleased", key, mods);
}
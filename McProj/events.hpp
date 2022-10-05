#pragma once

#include <GLFW/glfw3.h>

#include "Plugins.hpp"

void mouseMoved(GLFWwindow* window, double xpos, double ypos);

void mouseButtonPressedOrReleased(GLFWwindow* window, int button, int action, int mods);

void keyPressedOrReleased(GLFWwindow* window, int key, int scancode, int action, int mods);
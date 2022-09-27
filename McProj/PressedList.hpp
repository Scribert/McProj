#pragma once

#include <GLFW/glfw3.h>

class PressedList {
	typedef int (*Func)(GLFWwindow*, int);
	GLFWwindow* window;
	int (*func)(GLFWwindow*, int);

public:
	PressedList(GLFWwindow* window, Func func);
	bool operator[](int buttonOrKey);
};
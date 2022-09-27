#include "PressedList.hpp"

PressedList::PressedList(GLFWwindow* window, Func func) : window(window), func(func) {}

bool PressedList::operator[](int buttonOrKey) {
    return func(window, buttonOrKey);
}
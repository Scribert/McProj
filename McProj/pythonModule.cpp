#include <string>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <pybind11/embed.h>

#include "Component.hpp"
#include "PressedList.hpp"

namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(minecraft_editor, m) {
        
    py::class_<glm::vec2>(m, "vec2")
        .def(py::init<float, float>())
        .def_readwrite("x", &glm::vec2::x)
        .def_readwrite("y", &glm::vec2::y)
        .def_readwrite("r", &glm::vec2::r)
        .def_readwrite("g", &glm::vec2::g)
        .def_readwrite("s", &glm::vec2::s)
        .def_readwrite("t", &glm::vec2::t);

    py::class_<glm::vec3>(m, "vec3")
        .def(py::init<float, float, float>())
        .def_readwrite("x", &glm::vec3::x)
        .def_readwrite("y", &glm::vec3::y)
        .def_readwrite("z", &glm::vec3::z)
        .def_readwrite("r", &glm::vec3::r)
        .def_readwrite("g", &glm::vec3::g)
        .def_readwrite("b", &glm::vec3::b)
        .def_readwrite("s", &glm::vec3::s)
        .def_readwrite("t", &glm::vec3::t)
        .def_readwrite("p", &glm::vec3::p);

    py::class_<glm::ivec2>(m, "ivec2")
        .def(py::init<int , int>())
        .def_readwrite("x", &glm::ivec2::x)
        .def_readwrite("y", &glm::ivec2::y)
        .def_readwrite("r", &glm::ivec2::r)
        .def_readwrite("g", &glm::ivec2::g)
        .def_readwrite("s", &glm::ivec2::s)
        .def_readwrite("t", &glm::ivec2::t);
    
    py::class_<glm::ivec3>(m, "ivec3")
        .def(py::init<int, int, int>())
        .def_readwrite("x", &glm::ivec3::x)
        .def_readwrite("y", &glm::ivec3::y)
        .def_readwrite("z", &glm::ivec3::z)
        .def_readwrite("r", &glm::ivec3::r)
        .def_readwrite("g", &glm::ivec3::g)
        .def_readwrite("b", &glm::ivec3::b)
        .def_readwrite("s", &glm::ivec3::s)
        .def_readwrite("t", &glm::ivec3::t)
        .def_readwrite("p", &glm::ivec3::p);

    m.attr("KEY_UNKNOWN") = GLFW_KEY_UNKNOWN;
    m.attr("KEY_SPACE") = GLFW_KEY_SPACE;
    m.attr("KEY_APOSTROPHE") = GLFW_KEY_APOSTROPHE;
    m.attr("KEY_COMMA") = GLFW_KEY_COMMA;
    m.attr("KEY_MINUS") = GLFW_KEY_MINUS;
    m.attr("KEY_PERIOD") = GLFW_KEY_PERIOD;
    m.attr("KEY_SLASH") = GLFW_KEY_SLASH;
    m.attr("KEY_0") = GLFW_KEY_0;
    m.attr("KEY_1") = GLFW_KEY_1;
    m.attr("KEY_2") = GLFW_KEY_2;
    m.attr("KEY_3") = GLFW_KEY_3;
    m.attr("KEY_4") = GLFW_KEY_4;
    m.attr("KEY_5") = GLFW_KEY_5;
    m.attr("KEY_6") = GLFW_KEY_6;
    m.attr("KEY_7") = GLFW_KEY_7;
    m.attr("KEY_8") = GLFW_KEY_8;
    m.attr("KEY_9") = GLFW_KEY_9;
    m.attr("KEY_SEMICOLON") = GLFW_KEY_SEMICOLON;
    m.attr("KEY_EQUAL") = GLFW_KEY_EQUAL;
    m.attr("KEY_A") = GLFW_KEY_A;
    m.attr("KEY_B") = GLFW_KEY_B;
    m.attr("KEY_C") = GLFW_KEY_C;
    m.attr("KEY_D") = GLFW_KEY_D;
    m.attr("KEY_E") = GLFW_KEY_E;
    m.attr("KEY_F") = GLFW_KEY_F;
    m.attr("KEY_G") = GLFW_KEY_G;
    m.attr("KEY_H") = GLFW_KEY_H;
    m.attr("KEY_I") = GLFW_KEY_I;
    m.attr("KEY_J") = GLFW_KEY_J;
    m.attr("KEY_K") = GLFW_KEY_K;
    m.attr("KEY_L") = GLFW_KEY_L;
    m.attr("KEY_M") = GLFW_KEY_M;
    m.attr("KEY_N") = GLFW_KEY_N;
    m.attr("KEY_O") = GLFW_KEY_O;
    m.attr("KEY_P") = GLFW_KEY_P;
    m.attr("KEY_Q") = GLFW_KEY_Q;
    m.attr("KEY_R") = GLFW_KEY_R;
    m.attr("KEY_S") = GLFW_KEY_S;
    m.attr("KEY_T") = GLFW_KEY_T;
    m.attr("KEY_U") = GLFW_KEY_U;
    m.attr("KEY_V") = GLFW_KEY_V;
    m.attr("KEY_W") = GLFW_KEY_W;
    m.attr("KEY_X") = GLFW_KEY_X;
    m.attr("KEY_Y") = GLFW_KEY_Y;
    m.attr("KEY_Z") = GLFW_KEY_Z;
    m.attr("KEY_LEFT_BRACKET") = GLFW_KEY_LEFT_BRACKET;
    m.attr("KEY_BACKSLASH") = GLFW_KEY_BACKSLASH;
    m.attr("KEY_RIGHT_BRACKET") = GLFW_KEY_RIGHT_BRACKET;
    m.attr("KEY_GRAVE_ACCENT") = GLFW_KEY_GRAVE_ACCENT;
    m.attr("KEY_WORLD_1") = GLFW_KEY_WORLD_1;
    m.attr("KEY_WORLD_2") = GLFW_KEY_WORLD_2;
    m.attr("KEY_ESCAPE") = GLFW_KEY_ESCAPE;
    m.attr("KEY_ENTER") = GLFW_KEY_ENTER;
    m.attr("KEY_TAB") = GLFW_KEY_TAB;
    m.attr("KEY_BACKSPACE") = GLFW_KEY_BACKSPACE;
    m.attr("KEY_INSERT") = GLFW_KEY_INSERT;
    m.attr("KEY_DELETE") = GLFW_KEY_DELETE;
    m.attr("KEY_RIGHT") = GLFW_KEY_RIGHT;
    m.attr("KEY_LEFT") = GLFW_KEY_LEFT;
    m.attr("KEY_DOWN") = GLFW_KEY_DOWN;
    m.attr("KEY_UP") = GLFW_KEY_UP;
    m.attr("KEY_PAGE_UP") = GLFW_KEY_PAGE_UP;
    m.attr("KEY_PAGE_DOWN") = GLFW_KEY_PAGE_DOWN;
    m.attr("KEY_HOME") = GLFW_KEY_HOME;
    m.attr("KEY_END") = GLFW_KEY_END;
    m.attr("KEY_CAPS_LOCK") = GLFW_KEY_CAPS_LOCK;
    m.attr("KEY_SCROLL_LOCK") = GLFW_KEY_SCROLL_LOCK;
    m.attr("KEY_NUM_LOCK") = GLFW_KEY_NUM_LOCK;
    m.attr("KEY_PRINT_SCREEN") = GLFW_KEY_PRINT_SCREEN;
    m.attr("KEY_PAUSE") = GLFW_KEY_PAUSE;
    m.attr("KEY_F1") = GLFW_KEY_F1;
    m.attr("KEY_F2") = GLFW_KEY_F2;
    m.attr("KEY_F3") = GLFW_KEY_F3;
    m.attr("KEY_F4") = GLFW_KEY_F4;
    m.attr("KEY_F5") = GLFW_KEY_F5;
    m.attr("KEY_F6") = GLFW_KEY_F6;
    m.attr("KEY_F7") = GLFW_KEY_F7;
    m.attr("KEY_F8") = GLFW_KEY_F8;
    m.attr("KEY_F9") = GLFW_KEY_F9;
    m.attr("KEY_F10") = GLFW_KEY_F10;
    m.attr("KEY_F11") = GLFW_KEY_F11;
    m.attr("KEY_F12") = GLFW_KEY_F12;
    m.attr("KEY_F13") = GLFW_KEY_F13;
    m.attr("KEY_F14") = GLFW_KEY_F14;
    m.attr("KEY_F15") = GLFW_KEY_F15;
    m.attr("KEY_F16") = GLFW_KEY_F16;
    m.attr("KEY_F17") = GLFW_KEY_F17;
    m.attr("KEY_F18") = GLFW_KEY_F18;
    m.attr("KEY_F19") = GLFW_KEY_F19;
    m.attr("KEY_F20") = GLFW_KEY_F20;
    m.attr("KEY_F21") = GLFW_KEY_F21;
    m.attr("KEY_F22") = GLFW_KEY_F22;
    m.attr("KEY_F23") = GLFW_KEY_F23;
    m.attr("KEY_F24") = GLFW_KEY_F24;
    m.attr("KEY_F25") = GLFW_KEY_F25;
    m.attr("KEY_KP_0") = GLFW_KEY_KP_0;
    m.attr("KEY_KP_1") = GLFW_KEY_KP_1;
    m.attr("KEY_KP_2") = GLFW_KEY_KP_2;
    m.attr("KEY_KP_3") = GLFW_KEY_KP_3;
    m.attr("KEY_KP_4") = GLFW_KEY_KP_4;
    m.attr("KEY_KP_5") = GLFW_KEY_KP_5;
    m.attr("KEY_KP_6") = GLFW_KEY_KP_6;
    m.attr("KEY_KP_7") = GLFW_KEY_KP_7;
    m.attr("KEY_KP_8") = GLFW_KEY_KP_8;
    m.attr("KEY_KP_9") = GLFW_KEY_KP_9;
    m.attr("KEY_KP_DECIMAL") = GLFW_KEY_KP_DECIMAL;
    m.attr("KEY_KP_DIVIDE") = GLFW_KEY_KP_DIVIDE;
    m.attr("KEY_KP_MULTIPLY") = GLFW_KEY_KP_MULTIPLY;
    m.attr("KEY_KP_SUBTRACT") = GLFW_KEY_KP_SUBTRACT;
    m.attr("KEY_KP_ADD") = GLFW_KEY_KP_ADD;
    m.attr("KEY_KP_ENTER") = GLFW_KEY_KP_ENTER;
    m.attr("KEY_KP_EQUAL") = GLFW_KEY_KP_EQUAL;
    m.attr("KEY_LEFT_SHIFT") = GLFW_KEY_LEFT_SHIFT;
    m.attr("KEY_LEFT_CONTROL") = GLFW_KEY_LEFT_CONTROL;
    m.attr("KEY_LEFT_ALT") = GLFW_KEY_LEFT_ALT;
    m.attr("KEY_LEFT_SUPER") = GLFW_KEY_LEFT_SUPER;
    m.attr("KEY_RIGHT_SHIFT") = GLFW_KEY_RIGHT_SHIFT;
    m.attr("KEY_RIGHT_CONTROL") = GLFW_KEY_RIGHT_CONTROL;
    m.attr("KEY_RIGHT_ALT") = GLFW_KEY_RIGHT_ALT;
    m.attr("KEY_RIGHT_SUPER") = GLFW_KEY_RIGHT_SUPER;
    m.attr("KEY_MENU") = GLFW_KEY_MENU;

    m.attr("MOD_SHIFT") = GLFW_MOD_SHIFT;
    m.attr("MOD_CONTROL") = GLFW_MOD_CONTROL;
    m.attr("MOD_ALT") = GLFW_MOD_ALT;
    m.attr("MOD_SUPER") = GLFW_MOD_SUPER;
    m.attr("MOD_CAPS_LOCK") = GLFW_MOD_CAPS_LOCK;
    m.attr("MOD_NUM_LOCK") = GLFW_MOD_NUM_LOCK;

    m.attr("MOUSE_BUTTON_1") = GLFW_MOUSE_BUTTON_1;
    m.attr("MOUSE_BUTTON_2") = GLFW_MOUSE_BUTTON_2;
    m.attr("MOUSE_BUTTON_3") = GLFW_MOUSE_BUTTON_3;
    m.attr("MOUSE_BUTTON_4") = GLFW_MOUSE_BUTTON_4;
    m.attr("MOUSE_BUTTON_5") = GLFW_MOUSE_BUTTON_5;
    m.attr("MOUSE_BUTTON_6") = GLFW_MOUSE_BUTTON_6;
    m.attr("MOUSE_BUTTON_7") = GLFW_MOUSE_BUTTON_7;
    m.attr("MOUSE_BUTTON_8") = GLFW_MOUSE_BUTTON_8;
    m.attr("MOUSE_BUTTON_LAST") = GLFW_MOUSE_BUTTON_LAST;
    m.attr("MOUSE_BUTTON_LEFT") = GLFW_MOUSE_BUTTON_LEFT;
    m.attr("MOUSE_BUTTON_RIGHT") = GLFW_MOUSE_BUTTON_RIGHT;
    m.attr("MOUSE_BUTTON_MIDDLE") = GLFW_MOUSE_BUTTON_MIDDLE;

    py::class_<PressedList>(m, "PressedList")
        .def("__getitem__", &PressedList::operator[]);

    py::class_<Component::Iterator> component(m, "Component");

    py::enum_<Component::Type>(component, "Type")
        .value("Root", Component::Type::Root)
        .value("Scene", Component::Type::Scene);

    component
        .def("super", &Component::Iterator::getSupercomponent)
        .def("toSuper", &Component::Iterator::gotoSupercomponent)
        .def("sub", &Component::Iterator::getSubcomponent, py::arg("index"))
        .def("toSub", &Component::Iterator::gotoSubcomponent, py::arg("index"))
        .def("addSub", &Component::Iterator::insertNewComponent, py::arg("name"), py::arg("type"), py::arg("index"))
        .def("delSub", &Component::Iterator::eliminateSubcomponent, py::arg("index"))
        .def("delSubs", &Component::Iterator::eliminateAllSubcomponents)
        .def("moveSub", &Component::Iterator::moveSubcomponent, py::arg("toComponent"), py::arg("fromIndex"), py::arg("toIndex"))
        .def_property("name", &Component::Iterator::getComponentName, &Component::Iterator::renameComponent)
        .def_property_readonly("type", &Component::Iterator::getComponentType)
        .def_property_readonly("subCount", &Component::Iterator::getSubcomponentCount)
        .def_static("exists", &Component::componentExists, py::arg("name"))
        .def_static("get", &Component::getComponent, py::arg("name"));
}
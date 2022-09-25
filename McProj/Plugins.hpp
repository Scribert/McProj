#pragma once

#include <string>
#include <map>

#include <pybind11/pybind11.h>
#include <glm/glm.hpp>
namespace py = pybind11;

class Plugins : public std::map<std::string, py::module_> {
public:
	void loadPlugin(std::string name);
	void loadAllPlugins();
	void run(std::string function);
	void run(std::string function, glm::vec2 value);
};
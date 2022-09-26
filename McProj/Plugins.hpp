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
	void run(std::string function, int value1, int value2);
	void run(std::string function, double value);
	void run(std::string function, glm::vec2 value);
private:
	bool hasFunction(py::module_& module, std::string name);
	int numberOfArguments(py::module_& module, std::string name);
};
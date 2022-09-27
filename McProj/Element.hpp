#pragma once

#include <map>
#include <string>
#include <vector>

#include <pybind11/pybind11.h>
namespace py = pybind11;

class Element {
private:
	std::string _name;
public:
	py::dict attributes;
	py::list contents;

	Element(std::string name);
	std::string name() const;
};


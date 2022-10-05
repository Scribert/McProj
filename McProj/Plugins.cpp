#include "Plugins.hpp"

#include <fstream>
#include <iostream>

Plugins Plugins::plugins;

void Plugins::loadPlugin(std::string name) {
	try {
		this->insert(std::make_pair(name, py::module_::import(name.c_str())));
	}
	catch (py::error_already_set e) {
		std::cout << e.what();
	}
}

void Plugins::loadAllPlugins() {
	std::ifstream pluginsList;
	pluginsList.open("plugins/plugins_list.txt");
	std::string line;
	if (pluginsList.is_open()) {
		while (std::getline(pluginsList, line))
			loadPlugin(line);
	}
	else
		std::cout << "Failed to load \"plugins_list.txt\"";
}

void Plugins::run(std::string function, int value1, int value2) {
	for (auto itr = this->begin(); itr != this->end(); itr++) {

		if (hasFunction(itr->second, function)) {


			switch (numberOfArguments(itr->second, function)) {

			case 0:

				// Call the function `function` with no arguments
				try {
					itr->second.attr(function.c_str())();
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
				break;
			case 1:

				// Call the function `function` with one argument
				try {
					itr->second.attr(function.c_str())(value1);
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
				break;
			default:

				// Call the function `function` with two arguments
				try {
					itr->second.attr(function.c_str())(value1, value2);
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
				break;
			}
		}
	}
}

void Plugins::run(std::string function, double value) {
	for (auto itr = this->begin(); itr != this->end(); itr++) {

		if (hasFunction(itr->second, function)) {

			if (numberOfArguments(itr->second, function) == 0) {

				// Call the function `function` with no arguments
				try {
					itr->second.attr(function.c_str())();
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
			}
			else {

				// Call the function `function` with one argument
				try {
					itr->second.attr(function.c_str())(value);
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
			}
		}
	}
}

void Plugins::run(std::string function, glm::vec2 value) {
	for (auto itr = this->begin(); itr != this->end(); itr++) {

		if (hasFunction(itr->second, function)) {

			if (numberOfArguments(itr->second, function) == 0) {

				// Call the function `function` with no arguments
				try {
					itr->second.attr(function.c_str())();
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
			}
			else {

				// Call the function `function` with one argument
				try {
					itr->second.attr(function.c_str())(value);
				}
				catch (py::error_already_set e) {
					std::cout << e.what();
				}
			}
		}
	}
}

bool Plugins::hasFunction(py::module_& module, std::string name) {
	return module.attr("__dict__").attr("__contains__")(name).cast<bool>()
		&& py::hasattr(module.attr(name.c_str()), "__call__");
}

int Plugins::numberOfArguments(py::module_& module, std::string name) {
	return module.attr(name.c_str()).attr("__code__").attr("co_argcount").cast<int>();
}

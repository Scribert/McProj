#include "Plugins.hpp"

#include <fstream>
#include <iostream>

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
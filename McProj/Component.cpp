#include "Component.hpp"

#include <pybind11/pybind11.h>

namespace py = pybind11;

Component::Iterator::Iterator(Component* component) : component(component) {}

Component::Iterator Component::Iterator::getSupercomponent() {

	// Check if there is a supercomponent
	if (component->supercomponent == nullptr)
		throw py::attribute_error("This component has no supercomponent!");

	// Return the supercomponent
	return component->supercomponent;
}

void Component::Iterator::gotoSupercomponent() {

	// Check if there is a supercomponent
	if (component->supercomponent == nullptr)
		throw py::attribute_error("This component has no supercomponent!");

	// Go to supercomponent
	component = component->supercomponent;
}

Component::Iterator Component::Iterator::getSubcomponent(int index) {

	// Make it so -1 selects the last component
	int nindex = index < 0 ? component->subcomponents.size() + index : index;

	// Check if the index is valid
	if (nindex < 0 || nindex >= component->subcomponents.size())
		throw py::index_error("This component has no subcomponent at index " + std::to_string(nindex) + "!");

	// Return the supercomponent
	return component->subcomponents[nindex].get();
}

void Component::Iterator::gotoSubcomponent(int index) {

	// Make it so -1 selects the last component
	int nindex = index < 0 ? component->subcomponents.size() + index : index;

	// Check if the index is valid
	if (nindex < 0 || nindex >= component->subcomponents.size())
		throw py::index_error("This component has no subcomponent at index " + std::to_string(nindex) + "!");

	// Go to the subcomponent
	component = component->subcomponents[nindex].get();
}

void Component::Iterator::renameComponent(std::string_view name) {
	if (componentExists(name))
		throw py::value_error("There is already a component named " + std::string(name) + "!");
	
	// Delete the old name from componentNames and add the new one, then rename the component.
	componentNames.erase(component->name);
	componentNames.emplace(name, component);
	component->name = name;
}

void Component::Iterator::insertNewComponent(std::string_view name, Type type, int index) {

	// Make it so -1 selects the last component
	int nindex = index < 0 ? component->subcomponents.size() + index : index;

	// Check if the index is valid
	if (nindex < 0 || nindex > component->subcomponents.size())
		throw py::index_error("Cannot insert new component at index " + std::to_string(nindex) + "!");

	// Check if the name is already contained by subcomponents
	if (componentExists(name))
		throw py::value_error("There is already a component named " + std::string(name) + "!");

	// Add a new component to subcomponents
	component->subcomponents.emplace(component->subcomponents.begin() + nindex, std::make_unique<Component>(name, type, component));

	// Add the subcomponent's name to componentNames
	componentNames.emplace(name, component->subcomponents[nindex].get());
}

void Component::Iterator::eliminateSubcomponent(int index) {
	int nindex = index < 0 ? component->subcomponents.size() + index : index;

	if (nindex < 0 || nindex >= component->subcomponents.size())
		throw py::index_error("This component has no subcomponent at index " + std::to_string(nindex) + "!");

	// Eliminate the subcomponent
	component->subcomponents[nindex]->eliminateSelf();

	// Remove the subcomponent from the list
	component->subcomponents.erase(component->subcomponents.begin() + nindex);
}

void Component::Iterator::eliminateAllSubcomponents() {
	for (int i = 0; i < component->subcomponents.size(); i++) {
		component->subcomponents[i]->eliminateSelf();
	}

	component->subcomponents.clear();
}

void Component::Iterator::moveSubcomponent(Iterator toItr, int fromIndex, int toIndex) {

	// Make it so -1 selects the last component
	int fromNindex = fromIndex < 0 ? component->subcomponents.size() + fromIndex : fromIndex;
	int toNindex = toIndex < 0 ? component->subcomponents.size() + toIndex : toIndex;

	// Check if the indicies are valid
	if (fromNindex < 0 || fromNindex >= component->subcomponents.size())
		throw py::index_error("This component has no subcomponent at index " + std::to_string(fromNindex) + "!");

	if (toNindex < 0 || toNindex > toItr.component->subcomponents.size())
		throw py::index_error("Cannot insert new component at index " + std::to_string(toNindex) + "!");

	// Move one component from subcomponents to the other iterator's subcomponents
	toItr.component->subcomponents.emplace(toItr.component->subcomponents.begin() + toNindex,
		std::move(component->subcomponents[fromNindex]));

	// Remove the now empty unique_ptr from the subcomponents
	component->subcomponents.erase(component->subcomponents.begin() + fromIndex);

	// Change the component that componentNames[name] points to.
	componentNames[toItr.component->subcomponents[toIndex]->name] = toItr.component->subcomponents[toIndex].get();
}

std::string_view Component::Iterator::getComponentName() {
	return component->name;
}

Component::Type Component::Iterator::getComponentType() {
	return component->type;
}

int Component::Iterator::getSubcomponentCount() {
	return component->subcomponents.size();
}

Component Component::root("root", Component::Type::Root, nullptr);
std::unordered_map<std::string, Component*> Component::componentNames{ std::make_pair("root", &Component::root) };

Component::Component(std::string_view name, Type type, Component* supercomponent) : name(name), type(type), supercomponent(supercomponent) {}

void Component::eliminateSelf() {

	// Safely elimintate all subcomponents
	for (int i = 0; i < subcomponents.size(); i++) {
		subcomponents[i]->eliminateSelf();
	}

	subcomponents.clear();

	// Remove this component from componentNames
	componentNames.erase(name);
}

bool Component::componentExists(std::string_view name) {
	return componentNames.find(std::string(name)) != componentNames.end();
}

Component::Iterator Component::getComponent(std::string_view name) {
	auto component = componentNames.find(std::string(name));

	// Check if name is already contained by componentNames
	if (component == componentNames.end())
		throw py::value_error("Component does not exist!");

	return Iterator(component->second);
}
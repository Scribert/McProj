#include "Element.hpp"

Element::Element(std::string name) : _name(name) {}

std::string Element::name() const {
	return _name;
}
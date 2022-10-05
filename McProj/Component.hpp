#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Component {
public:

	enum class Type {
		Root,
		Scene
	};

	class Iterator {

		friend class Component;

		Component* component;

		Iterator(Component* component);

	public:
		Iterator getSupercomponent();
		void gotoSupercomponent();
		Iterator getSubcomponent(int index);
		void gotoSubcomponent(int index);
		void renameComponent(std::string_view name);
		void insertNewComponent(std::string_view name, Type type, int index);
		void eliminateSubcomponent(int index);
		void eliminateAllSubcomponents();
		void moveSubcomponent(Iterator toItr, int fromIndex, int toIndex);
		std::string_view getComponentName();
		Type getComponentType();
		int getSubcomponentCount();
	};
private:
	
	std::string name;
	const Type type;
	Component* supercomponent;
	std::vector<std::unique_ptr<Component>> subcomponents;

	static Component root;
	static std::unordered_map<std::string, Component*> componentNames;

	// Frees all subcomponents and removes its name from componentNames
	void eliminateSelf();

public:

	Component(std::string_view name, Type type, Component* supercomponent);

	static bool componentExists(std::string_view name);
	static Iterator getComponent(std::string_view name);

};


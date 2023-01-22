#pragma once
#include <cstdint>
#include <vector>
#include <memory>
#include <bitset>

class Component;
class Entity;

namespace {
	uint32_t ENTITY_ID_COUNTER = 0;
	const uint32_t MAX_COMPONENTS = 32;
}

inline uint32_t getTypeID() {
	static uint32_t COMPONENT_ID_COUNTER = 0;
	return COMPONENT_ID_COUNTER++;
}

template<typename T> inline uint32_t getComponentID() {
	return getTypeID();
}

class Component {
public:
	Entity* entity;

	virtual void init();
	virtual void update();
	virtual void draw();
};

class Entity {
public:
	Entity() {
		this->ID = ENTITY_ID_COUNTER++;
	}

	template <typename T> bool hasComponent() {
		return this->componentBitset[getComponentID<T>()];
	}

	template <typename T, typename... Args> T& addComponent(Args&&... args) {
		T* c(new T(std::forward<Args>(args)...);
		c->entity = this;
		std::unique_ptr<Component> c_unique(c);
		this->components.emplace_back(c_unique);

		this->componentBitset[getComponentID<T>()] = true;

		c->init();
		return *c;
	}

private:
	uint32_t ID;
	std::vector<std::unique_ptr<Component>> components;
	std::bitset<MAX_COMPONENTS> componentBitset;
};
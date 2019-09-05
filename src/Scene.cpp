#include "Scene.h"

Scene::Scene(const std::string &identifier) : identifier(identifier) {}

Scene::~Scene() {}

const std::string &Scene::getIdentifier() const {
    return identifier;
}

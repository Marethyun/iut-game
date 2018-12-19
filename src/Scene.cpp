#include "Scene.h"

Scene::Scene(const std::string &identifier) : identifier(identifier) {}

const std::string &Scene::getIdentifier() const {
    return identifier;
}

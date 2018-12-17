#include "Scene.h"

Scene::Scene(const unsigned int &height, const unsigned int &width, const std::string &identifier)
        : height(height), width(width), identifier(identifier), stageMatrix(CellMatrix<Cell>(height, width, Cell())) {}

unsigned int Scene::getHeight() const {
    return height;
}

unsigned int Scene::getWidth() const {
    return width;
}

const std::string &Scene::getIdentifier() const {
    return identifier;
}

#include "DifficultyScene.h"

DifficultyScene::DifficultyScene(const std::string &identifier) : Scene(identifier) {
    
}

void DifficultyScene::update(const char &lastChar) {
    
}

Matrix DifficultyScene::render() {
       return Matrix(1, 1, Cell());
}

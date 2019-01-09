#include "testscene.h"

#include <iostream>
#include "Game.h"
#include "Color.h"

using namespace std;

TestScene::TestScene(const std::string &identifier) : Scene(identifier) {
    
}

void TestScene::update(const char &c){
    if (c == 'p') Game::get()->stop();
    
    Location nextLocation = jLocation;
    
    switch (c) {
        case 'z':
        case 'Z':
            nextLocation.setY(nextLocation.getY() - 1);
            break;
        case 'q':
        case 'Q':
            nextLocation.setX(nextLocation.getX() - 1);
            break;
        case 's':
        case 'S':
            nextLocation.setY(nextLocation.getY() + 1);
            break;
        case 'd':
        case 'D':
            nextLocation.setX(nextLocation.getX() + 1);
    }
    
    if (matrix.isInBounds(nextLocation)) {
        jLocation = nextLocation;
    }
}

Matrix TestScene::render(){
    
    Matrix nextMatrix = matrix;
    
    nextMatrix.merge(playerLocation, Cell(Color::red + Color::bold, '&'));
    
    return nextMatrix;
}

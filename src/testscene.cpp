#include "testscene.h"

#include "Game.h"
#include "Color.h"

TestScene::TestScene(const std::string &identifier) : Scene(identifier) {
    
}

void TestScene::update(const char &c){
    if (c == 'q') Game::get()->stop();
}

Matrix TestScene::render(){
    return Matrix(10, 10, Cell(Color::bg_yellow));
}

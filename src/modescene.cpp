#include "modescene.h"
#include <vector>
#include "Game.h"
#include <iostream>

using namespace std;

typedef vector <char> CVline; //un type représentant une ligne de la grille
typedef vector <CVline> CMatrix; //un type repésentant la grille
typedef pair <unsigned, unsigned> CExtract; //un type représentant une coordoné dans la grille

ModeScene::ModeScene(const std::string &identifier) : Scene(identifier) {

}

void ModeScene::update(const char &c){
    if (c == '\n') Game::get()->stop();
}

Matrix ModeScene::render(){
    Matrix MatSombre (37, 37, Cell('#'));
    return Matrix.merge(5,5, MatSombre);
}


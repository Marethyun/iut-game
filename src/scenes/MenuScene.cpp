#include "MenuScene.h"

#include "../Color.h"
#include "../Game.h"
#include <math.h>

using namespace std;

MenuScene::MenuScene(const string &identifier) : Scene(identifier) {
    srand(time(NULL));
}

void MenuScene::update(const char &c) {
    switch (c) {
        case 'q':
        case 'Q':
            Game::get()->stop();
            break;

        case 'a':
            Game::get()->loadScene("difficulty");
            break;
    }
}

Matrix MenuScene::render() {
    Matrix global(20, 40, Cell(Color::bg_white));
    
    global.text(3, 2, 34, Color::black, "Aladinde et le labyrinthe magique");
    
    global.text(13, 7, Color::black, "A - Jouer");
    
    global.text(13, 9, Color::black, "B - Tutoriel");
    
    global.text(13, 11, Color::black, "C - Histoire");

    global.text(13, 14, Color::black, "Q - Quitter");
    
    
    return global;
}

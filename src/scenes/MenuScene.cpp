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
            Game::get()->stop();
            break;
    }
}

Matrix MenuScene::render() {
    Matrix global(20, 40, Cell(Color::bg_white));
    
    global.text(3, 2, 34, Color::black, "Aladinde et le labyrinthe magique");
    
    Matrix playText(1, 14, Cell());
    playText.text(0, 0, Color::black, "Jouer");
    playText.text(playText.getWidth() - 3, 0, Color::black, "<A>");
    
    Matrix tutorialText(1, 14, Cell());
    tutorialText.text(0, 0, Color::black, "Tutoriel");
    tutorialText.text(tutorialText.getWidth() - 3, 0, Color::black, "<B>");
    
    Matrix storyText(1, 14, Cell());
    storyText.text(0, 0, Color::black, "Histoire");
    storyText.text(storyText.getWidth() - 3, 0, Color::black, "<C>");
    
    Matrix quitText(1, 14, Cell());
    quitText.text(0, 0, Color::black, "Quitter");
    quitText.text(quitText.getWidth() - 3, 0, Color::black, "<Q>");
    
    global.merge(13, 7, playText);
    global.merge(13, 9, tutorialText);
    global.merge(13, 11, storyText);
    global.merge(13, 13, quitText);
    
    return global;
}

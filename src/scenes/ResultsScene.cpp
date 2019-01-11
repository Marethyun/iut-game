#include "ResultsScene.h"

#include "../Game.h"
#include "../Color.h"
#include <sstream>

using namespace std;

ResultsScene::ResultsScene(const std::string &identifier, const unsigned &steps, const Difficulty &originalDifficulty) 
    : Scene(identifier), steps(steps), originalDifficulty(originalDifficulty)

{
    
}

void ResultsScene::update(const char &c) {
    if (c == 'r') {
        Game::get()->loadScene("main_menu");
        Game::get()->eraseScene(this->getIdentifier());
    }
}

Matrix ResultsScene::render() {
    
    Matrix global(20, 40, Cell(Color::bg_green));
    
    global.text(4, 2, 34, Color::white + Color::bold, "Bravo, Aladinde est desormais heureux !");
    
    ostringstream oss;
    
    oss << this->steps;
    
    global.text(5, 5, Color::white + Color::bold, "> Aladinde a fait " + oss.str() + " pas.");
    global.text(5, 7, Color::white + Color::bold, "> La difficulte etait: " + this->originalDifficulty.name);
    
    Matrix aladindeNote(5, 32, Cell(Color::bg_white));
    
    aladindeNote.merge(3, 3, Cell(Color::yellow, '&'));
    
    aladindeNote.text(2, 2, Color::black + Color::blink, "'''");
    
    aladindeNote.text(7, 1, 27, Color::black, "Glouglou Glouglouglou ! Glouglouglou. Glouglouglouglouglou !!");
    
    global.replace(4, 10, aladindeNote);
    
    global.text(4, 17, Color::white + Color::bold, "R - Retourner au menu principal");
    
    return global;
}

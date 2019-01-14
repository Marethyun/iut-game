#include "StoryScene.h"

#include "../Game.h"
#include "../Color.h"

using namespace std;

StoryScene::StoryScene(const std::string &identifier) : Scene(identifier) {}

void StoryScene::update(const char &c) {
    if (c == 'r') Game::get()->loadScene("main_menu");
}

Matrix StoryScene::render() {
    Matrix global(20, 40, Cell(Color::bg_white));
    
    global.text(3, 1, Color::black, "Histoire d'Aladinde le dindon");
    
    global.text(2, 3, 36, Color::black, "Aladinde le dindon, s'ennuyant a la ferme au cote de ses quatres dindonnes, decida de sauter la barriere pour aller visiter le monde.");
    
    global.text(2, 9, 36, Color::black, "Au bout de trente minutes d'expedition dindonnesque, Aladinde le dindon se rendit compte que le monde exterieur n'etait pas tres dindonnesque et voulut rentrer. Tout dindon qu'il est, Aladinde le dindon ne savait plus comment rentrer aupres de ses dindonnes.");
    
    global.text(3, 18, Color::black, "R - Retour au menu");
    
    return global;
}

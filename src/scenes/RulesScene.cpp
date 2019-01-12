#include "RulesScene.h"

#include "../Color.h"
#include "../Game.h"
#include "../Config.h"

#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

RulesScene::RulesScene(const std::string &identifier) : Scene(identifier) {}

void RulesScene::update(const char &c) {
    if (c == 'r') Game::get()->loadScene("main_menu");
}

Matrix RulesScene::render() {
    
    Matrix global(20, 40, Cell(Color::bg_white));
    
    global.text(3, 1, 34, Color::black, "Regles du jeu (comment jouer)");
    
    global.text(2, 3, 36, Color::black, "Le but est de faire sortir Aladinde (&) du labydinde. Pour sortir (@), vous devez trouver toutes les clefs (.). Aladinde est petit et ne voit pas bien dans les hautes herbes (#). Recuperez des lunettes (%) pour ameliorer ou degrader sa vue.");
    
    global.text(2, 11, 36, Color::black, "Controles:");
    
    Config* conf = Config::get();
    
    ostringstream oss;
    oss << conf->keyUp() << conf->keyLeft() << conf->keyDown() << conf->keyRight();
    string movement = oss.str();
    transform(movement.begin(), movement.end(), movement.begin(), ::toupper);
    
    global.text(2, 13, 36, Color::black, "Mouvement: " + movement);
    
    oss.str(std::string());
    oss << conf->keyGiveUp();
    string giveUp = oss.str();
    transform(giveUp.begin(), giveUp.end(), giveUp.begin(), ::toupper);
    
    global.text(2, 14, 36, Color::black, "Abandonner (retour au menu): " + giveUp);
    
    global.text(3, 18, Color::black, "R - Retour au menu");
    
    return global;
}

#include "DifficultyScene.h"

#include "../Color.h"
#include "../Game.h"
#include "../Difficulty.h"
#include "../Remarks.h"

#include "GameScene.h"

using namespace std;

DifficultyScene::DifficultyScene(const std::string &identifier) : Scene(identifier) {
    
}

void DifficultyScene::update(const char &c) {
    
    Game* game = Game::get();
    
    string identifier = "game_core";
    Scene* gameScene;
    
    switch (c) {
        case 'a':
            // Facile: 11x11, 5 obj, 60%, 3 clefs, 3 herbes de 2, vision de 2
            gameScene = new GameScene(identifier, Difficulty("Facile", 11, 11, 5, 0.6, 3, 3, 2, 2));
            
            game->addScene(gameScene);
            game->loadScene(*gameScene);
            break;
            
        case 'b':
            // Normal: 21x21, 10 obj, 50%, 5 clefs, 5 herbes de 3, vision de 2
            gameScene = new GameScene(identifier, Difficulty("Normal", 21, 21, 10, 0.5, 5, 5, 3, 2));
            game->addScene(gameScene);
            game->loadScene(*gameScene);
            break;
        
        case 'c':
            // Difficile: 41x41, 20 obj, 40%, 10 clefs, 10 herbes de 4, vision de 2
            gameScene = new GameScene(identifier, Difficulty("Difficile", 41, 41, 20, 0.4, 10, 10, 4, 2));
            game->addScene(gameScene);
            game->loadScene(*gameScene);
            break;
        
        case 'd':
            // Phasianidae: 101x101, 50 obj, 40%, 15 clefs, 20 herbes de 5, vision de 2
            gameScene = new GameScene(identifier, Difficulty("Phasianidae", 101, 101, 50, 0.4, 15, 20, 5, 2));
            game->addScene(gameScene);
            game->loadScene(*gameScene);
            break;
        
        case 'r':
            game->loadScene("main_menu");
            break;
    }
}

Matrix DifficultyScene::render() {

    Matrix global(20, 40, Cell(Color::bg_white));

    global.text(3, 1, 34, Color::black, "Choisissez une difficulte:");

    Matrix easy(1, 30, Cell());
    easy.text(0, 0, Color::black, "A - Facile");
    easy.text(easy.getWidth() - 7, 0, Color::black, "(11x11)");

    Matrix normal(1, 30, Cell());
    normal.text(0, 0, Color::black, "B - Normal");
    normal.text(normal.getWidth() - 7, 0, Color::black, "(21x21)");

    Matrix hard(1, 30, Cell());
    hard.text(0, 0, Color::black, "C - Difficile");
    hard.text(hard.getWidth() - 7, 0, Color::black, "(41x41)");

    Matrix phasianidae(1, 30, Cell());
    phasianidae.text(0, 0, Color::black, "D - Phasianidae");
    phasianidae.text(phasianidae.getWidth() - 9, 0, Color::black, "(101x101)");

    global.merge(5, 4, easy);
    global.merge(5, 5, normal);
    global.merge(5, 6, hard);
    global.merge(5, 7, phasianidae);

    global.text(3, 9, Color::black, "Le saviez-vous?");
    
    string remark = Remarks::getRandom();
    
    global.text(1, 11, 38, Color::black, remark);

    global.text(3, 18, Color::black, "R - Retour au menu");

    return global;
}

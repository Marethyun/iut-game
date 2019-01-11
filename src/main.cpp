#include <iostream>
#include <string>

#include "Scene.h"
#include "Game.h"
#include "Color.h"
#include "Terminal.h"

#include "scenes/GameScene.h"
#include "scenes/MenuScene.h"
#include "scenes/DifficultyScene.h"

#include "Map.h"

using namespace std;

int main() {
    Game* game = Game::get();
    Scene* mainMenu = new MenuScene("main_menu");
    Scene* gameScene = new GameScene("game_core", Difficulty(11, 11, 30, 0.5, 3, 3, 2, 2));
    Scene* difficultyMenu = new DifficultyScene("difficulty");

    game->addScene(mainMenu);
    game->addScene(gameScene);
    game->addScene(difficultyMenu);
    
    game->loadScene(*difficultyMenu);
    game->start();
    
    Terminal::clear();

    return 0;
}

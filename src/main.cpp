#include <iostream>
#include <string>

#include "Scene.h"
#include "Game.h"
#include "Color.h"
#include "Terminal.h"

#include "scenes/MenuScene.h"
#include "scenes/DifficultyScene.h"

#include "Map.h"

using namespace std;

int main() {
    Game* game = Game::get();
    Scene* mainMenu = new MenuScene("main_menu");
    Scene* difficultyMenu = new DifficultyScene("difficulty");

    game->addScene(mainMenu);
    game->addScene(difficultyMenu);
    
    game->loadScene(*mainMenu);
    game->start();
    
    Terminal::clear();

    return 0;
}

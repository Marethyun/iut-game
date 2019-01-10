#include <iostream>
#include <string>

#include "Scene.h"
#include "Game.h"
#include "Color.h"
#include "Terminal.h"

#include <unistd.h>
#include <iomanip>
#include <math.h>

#include "scenes/GameScene.h"
#include "scenes/MenuScene.h"

#include "Map.h"

using namespace std;

int main() {
    Game* game = Game::get();
    Scene* mainMenu = new MenuScene("main_menu");
    Scene* gameScene = new GameScene("game_core", Map(11, 11, Location(), 40, 8, 4, 8), 0);
    
    game->addScene(mainMenu);
    game->addScene(gameScene);
    
    game->loadScene(*gameScene);
    game->start();
    
    Terminal::clear();

    return 0;
}

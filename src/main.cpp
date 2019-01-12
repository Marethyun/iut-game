#include <iostream>
#include <string>

#include "Scene.h"
#include "Game.h"
#include "Color.h"
#include "Terminal.h"
#include "Remarks.h"
#include "Config.h"

#include "scenes/MenuScene.h"
#include "scenes/DifficultyScene.h"
#include "scenes/RulesScene.h"
#include "scenes/StoryScene.h"

#include "Map.h"

using namespace std;

int main() {
    Game* game = Game::get();
    
    Scene* mainMenu = new MenuScene("main_menu");
    Scene* difficultyMenu = new DifficultyScene("difficulty");
    Scene* rules = new RulesScene("rules");
    Scene* story = new StoryScene("story");
    
    game->addScene(mainMenu);
    game->addScene(difficultyMenu);
    game->addScene(rules);
    game->addScene(story);
    
    game->loadScene(*mainMenu);
    game->start();
    
    Terminal::clear();

    return 0;
}

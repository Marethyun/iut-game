#include <iostream>
#include <string>

#include "Scene.h"
#include "Game.h"
#include "Color.h"
#include "Terminal.h"

#include <unistd.h>

#include "modescene.h"
#include "Game.h"

using namespace std;

int main() {

    ModeScene ms = ModeScene("mode_scene");

    Scene* rms = &ms;

    Game::get()->addScene(rms);
    Game::get()->loadScene(ms);

    Game::get()->start();

    return 0;
}

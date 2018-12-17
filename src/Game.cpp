#include <unordered_map>
#include "Game.h"
#include "exception/GameException.h"

using namespace std;

Game::Game() = default;

Game* Game::singleton = nullptr;

// Singleton
Game *Game::get() {
    if (!singleton){
        singleton = new Game();
    }
    return singleton;
}

void Game::addScene(Scene* &scene) {
    string identifier = scene->getIdentifier(); // Imperative, getter returns a const and we need a non-const
    if (this->scenes.count(&identifier)){
        throw GameException("scene with id '" + identifier + "' is already registered");
    }
    this->scenes.insert(pair<string*, Scene*>(&identifier, scene));
}

void Game::loadScene(std::string &identifier) {
    auto it = scenes.find(&identifier);

    if (it != scenes.end()){
        this->currentScene = it->second;
    } else {
        throw GameException("scene with id '" + identifier + "' not found");
    }
}

void Game::loadScene(Scene &scene) {
    string id = scene.getIdentifier();
    loadScene(id);
}

unsigned Game::getFps() const {
    return this->fps;
}

void Game::setFps(const unsigned &fps) {
    this->fps = fps;
}

void Game::start() {

}

void Game::stop() {

}

bool Game::isRunning() const {
    return running;
}

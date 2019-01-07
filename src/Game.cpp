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

Scene* Game::getScene(std::string &identifier) {
    auto it = scenes.find(&identifier);

    if (it != scenes.end()){
        return it->second;
    } else {
        throw GameException("scene with id '" + identifier + "' not found");
    }
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
        this->currentScene = &identifier;
    } else {
        throw GameException("scene with id '" + identifier + "' not found");
    }
}

void Game::loadScene(Scene &scene) {
    string id = scene.getIdentifier();
    loadScene(id);
}

void Game::start() {
    this->running = true;
    while (this->running){
        string* identifier = currentScene;
        Scene* s = this->getScene(*identifier);
    }
}

void Game::stop() {
    this->running = false;
}

bool Game::isRunning() const {
    return running;
}

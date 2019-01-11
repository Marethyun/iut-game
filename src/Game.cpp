#include <unordered_map>
#include "Game.h"
#include "exception/GameException.h"
#include "Terminal.h"
#include <unistd.h>

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
    auto it = scenes.find(identifier);

    if (it != scenes.end()){
        return it->second;
    } else {
        throw GameException("scene with id '" + identifier + "' not found");
    }
}

void Game::addScene(Scene* &scene) {
    string identifier = scene->getIdentifier(); // Imperative, getter returns a const and we need a non-const
    if (this->scenes.count(identifier)){
        throw GameException("scene with id '" + identifier + "' is already registered");
    }
    this->scenes.insert(pair<string, Scene*>(identifier, scene));
}

void Game::loadScene(const std::string &identifier) {
    auto it = scenes.find(identifier);

    if (it != scenes.end()){
        this->currentScene = identifier;
    } else {
        throw GameException("scene with id '" + identifier + "' not found");
    }
}

void Game::loadScene(Scene &scene) {
    string id = scene.getIdentifier();
    loadScene(id);
}

void Game::eraseScene(const std::string &identifier) {
    auto it = scenes.find(identifier);

    if (it != scenes.end()){
        this->scenes.erase(identifier);
    } else {
        throw GameException("scene with id '" + identifier + "' not found");
    }
}

void Game::start() {
    this->running = true;
    char c;
    while (this->running) {
        string identifier = currentScene;
        Scene* s = this->getScene(identifier);
            
        Matrix nextMatrix = s->render();
        Terminal::clear();
        Terminal::matrix(nextMatrix);
        
        c = Terminal::getch();
        
        s->update(c);
    }
}

void Game::stop() {
    this->running = false;
}

bool Game::isRunning() const {
    return running;
}

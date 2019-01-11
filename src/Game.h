#ifndef IUT_GAME_GAME_H
#define IUT_GAME_GAME_H

#include <map>
#include "Matrix.h"
#include "Scene.h"

class Game {
private:

    static Game* singleton;
    Game();

    std::map<std::string, Scene*> scenes = std::map<std::string, Scene*>();
    std::string currentScene = "";

    bool running = false;
    
    Scene* getScene(std::string &identifier);

public:
    static Game* get();

    void addScene(Scene* &scene);

    void loadScene(const std::string &identifier);
    void loadScene(Scene &scene);

    bool isRunning() const;

    void start();
    void stop();
};

#endif

#ifndef IUT_GAME_GAME_H
#define IUT_GAME_GAME_H

#include <map>
#include "CellMatrix.h"
#include "Scene.h"

// This class is a singleton
class Game {
private:

    static Game* singleton;
    Game();

    std::map<std::string*, Scene> scenes = std::map<std::string*, Scene>();
    Scene* currentScene = nullptr;

    unsigned fps = 30;
    bool running = false;

public:
    static Game* get();

    void addScene(Scene & scene);

    void loadScene(std::string &identifier);
    void loadScene(Scene & scene);

    unsigned getFps() const;
    void setFps(const unsigned & fps);
    bool isRunning() const;

    void start();
    void stop();
};

#endif

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Matrix.h"
#include "../Scene.h"

class GameScene : public Scene
{
public:
    GameScene(const std::string &identifier);
    
    void update(char &lastChar);
    
    Matrix render();
    
private:
    
};

#endif // GAMESCENE_H

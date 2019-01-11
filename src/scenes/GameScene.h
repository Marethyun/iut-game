#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Matrix.h"
#include "../Scene.h"
#include "../Map.h"
#include "../Player.h"
#include "../Difficulty.h"

class GameScene : public Scene
{
public:
    GameScene(const std::string &identifier, const Difficulty &difficulty);
    
    void update(const char &lastChar) override;
    Matrix render() override;
    
private:
    Map gameMap;
    
    unsigned claimedKeys = 0;
    unsigned totalKeys = 0;
    
    Player player;
    Difficulty difficulty;
    unsigned stepsCount = 0;
    
    /**
     * @brief lastNote Dernière remarque du dindon
     */
    std::string lastNote;
    
    bool exitOpened = false;
    bool constraintVision = false;
};

#endif // GAMESCENE_H

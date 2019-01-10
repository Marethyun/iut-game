#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Matrix.h"
#include "../Scene.h"
#include "../Map.h"
#include "../Player.h"

class GameScene : public Scene
{
public:
    GameScene(const std::string &identifier, const Map &gameMap, const unsigned &difficulty);
    
    void update(const char &lastChar) override;
    Matrix render() override;
    
private:
    Map gameMap;
    
//    unsigned claimedObjects;
    unsigned claimedKeys = 0;
    unsigned totalKeys = 0;
    
    Player player;
    /**
     * @brief difficulty Difficulté du jeu
     * 
     * 0 Facile         (10x10, 2 clefs, 4 herbes (2), 3 objets (0.6)
     * 1 Normal         (20x20, 4 clefs, 6 herbes (3), 7 objets (0.5)
     * 2 Difficile      (30x30, 10 clefs, 12 herbes (4), 10 objets (0.4) 
     * 3 Expert         (50x50, 20 clefs, 20 herbes (5), 15 objets (0.3)
     * 4 Phasianidae    (100x100, 10 clefs, 20 herbes (6), 15 objets (0.1)
     */
    unsigned difficulty = 0;
    unsigned stepsCount = 0;
    
    /**
     * @brief lastNote Dernière remarque du dindon
     */
    std::string lastNote;
    
    bool exitOpened = false;
    bool constraintVision = false;
};

#endif // GAMESCENE_H

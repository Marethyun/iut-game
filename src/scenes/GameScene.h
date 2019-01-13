#ifndef GAMESCENE_H
#define GAMESCENE_H

/**
 * @file GameScene.h
 * @brief Header for the GameScene class
 * @author Ange Bacci
 */

#include "../Matrix.h"
#include "../Scene.h"
#include "../Map.h"
#include "../Player.h"
#include "../Difficulty.h"

/**
 * @class GameScene
 * @brief The core scene, renders the game
 *
 * This Scene renders the game itself
 */
class GameScene : public Scene
{
public:
    /**
     * @brief Initializes the scene with its identifier, and with a game difficulty
     *
     * Generates the map, and hydrates all the properties.
     *
     * @param identifier The scene identifier
     * @param difficulty The game difficulty
     */
    GameScene(const std::string &identifier, const Difficulty &difficulty);

    /**
     * @copydoc Scene::update(const char &lastChar)
     *
     * Updates the game info, from the player movement.
     * The movement keys are retrieved from the configuration file.
     *
     * May instantiate and load the ResultsScene to the game, when the player got all the keys and went through the exit.
     * When it does, erases the current instance from the game.
     */
    void update(const char &lastChar) override;

    /**
     * @copydoc Scene::render()
     *
     * Renders the game from the player position, crops the map with the user vision.
     * Updates the HUD with steps, keys, and notes from Aladinde.
     */
    Matrix render() override;
    
private:
    /**
     * @brief The game map
     */
    Map gameMap;

    /**
     * @brief The claimed keys
     */
    unsigned claimedKeys = 0;

    /**
     * @brief The total keys
     */
    unsigned totalKeys = 0;

    /**
     * @brief The player
     */
    Player player;

    /**
     * @brief The game difficulty
     */
    Difficulty difficulty;

    /**
     * The player steps since the start
     */
    unsigned stepsCount = 0;
    
    /**
     * @brief lastNote Last note from Aladinde the turkey
     */
    std::string lastNote;

    /**
     * @brief Whether the exit is opened or not
     *
     * Does the player got all the required keys ?
     */
    bool exitOpened = false;

    /**
     * @brief Whether the vision is constraint or not
     *
     * true when the player is on a grass cell, false otherwise
     */
    bool constraintVision = false;
};

#endif // GAMESCENE_H

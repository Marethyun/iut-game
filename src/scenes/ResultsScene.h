#ifndef RESULTSSCENE_H
#define RESULTSSCENE_H

/**
 * @file ResultsScene.h
 * @brief Header for the ResultsScene class
 * @author Ange Bacci
 */

#include "../Scene.h"
#include "../Difficulty.h"

/**
 * @class ResultsScene
 * @brief The game results screen
 *
 * Renders the game results after the end of a game, when the player goes through the maze end
 */
class ResultsScene : public Scene
{
public:
    /**
     * @brief Initializes the scene
     *
     * @param identifier The scene identifier
     * @param steps The steps count from the previous game
     * @param originalDifficulty The game difficulty chosen
     */
    ResultsScene(const std::string &identifier, const unsigned &steps, const Difficulty &originalDifficulty);

    /**
     * @copydoc Scene::update(const char &lastChar)
     *
     * Simply waits for the user to press R to return to the main menu (erase this scene, load the main menu one)
     */
    void update(const char &lastChar) override;

    /**
     * @copydoc Scene::render()
     *
     * Renders the previous game info: steps and difficulty.
     * Adds an Aladinde happy note.
     */
    Matrix render() override;
private:
    /**
     * @brief The steps count from the previous game
     */
    const unsigned steps = 0;

    /**
     * @brief The game difficulty chosen
     */
    Difficulty originalDifficulty;
};

#endif // RESULTSSCENE_H

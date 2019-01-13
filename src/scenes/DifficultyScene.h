#ifndef DIFFICULTYSCENE_H
#define DIFFICULTYSCENE_H

/**
 * @file DifficultyScene.h
 * @brief Header for the DifficultyScene class
 * @author Ange Bacci
 */

#include "../Scene.h"

/**
 * @class DifficultyScene
 * @brief The difficulty menu
 *
 * This Scene renders the difficulty selection menu, before launching the game.
 */
class DifficultyScene : public Scene
{
public:
    /**
     * @brief Initializes the scene with its identifier
     * @param identifier The scene identifier
     */
    DifficultyScene(const std::string &identifier);

    /**
     * @copydoc Scene::update(const char &lastChar)
     *
     * The user may press A, B, C, or D to choose the difficulty. The method will so load the GameScene with the chosen difficulty.
     * The user may press R to go back to the main menu.
     */
    void update(const char &lastChar) override;

    /**
     * @copydoc Scene::render()
     *
     * Renders the menu with a remark, using the Remark class.
     */
    Matrix render() override;
};

#endif // DIFFICULTYSCENE_H

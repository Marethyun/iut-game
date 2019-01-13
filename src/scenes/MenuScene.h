#ifndef MENUSCENE_H
#define MENUSCENE_H

/**
 * @file MenuScene.h
 * @brief Header for the MenuScene class
 * @author Ange Bacci
 */

#include "../Scene.h"

/**
 * @class MenuScene
 * @brief The main menu scene
 *
 * Renders the main menu
 */
class MenuScene : public Scene
{
public:
    /**
     * @brief Initializes the scene with its identifier
     * @param identifier The scene identifier
     */
    MenuScene(const std::string &identifier);

    /**
     * @copydoc Scene::update(const char &lastChar)
     *
     * The user may press A, B, or C to be redirected through the other menus.
     * The user may press Q to quit and terminate the game.
     *
     * @see DifficultyScene
     * @see RulesScene
     * @see StoryScene
     */
    void update(const char &lastChar) override;

    /**
     * @copydoc Scene::render()
     *
     * Just renders the game name and the menu entries as texts.
     */
    Matrix render() override;
};

#endif // MENUSCENE_H

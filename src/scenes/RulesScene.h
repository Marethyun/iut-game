#ifndef RULESSCENE_H
#define RULESSCENE_H

/**
 * @file RulesScene.h
 * @brief Header for the RulesScene class
 * @author Ange Bacci
 */

#include "../Scene.h"

/**
 * @class RulesScene
 * @brief The rules menu
 *
 * Renders the game rules and the keymap to play
 */
class RulesScene : public Scene
{
public:
    /**
     * @brief Initializes the scene with its identifier
     * @param identifier The scene identifier
     */
    RulesScene(const std::string &identifier);

    /**
     * @copydoc Scene::update(const char &lastChar)
     *
     * Simply waits for the user to press R to return to the main menu.
     */
    void update(const char &lastChar) override;

    /**
     * @copydoc Scene::render()
     *
     * Renders the rules and the keys as texts
     */
    Matrix render() override;
};

#endif // RULESSCENE_H

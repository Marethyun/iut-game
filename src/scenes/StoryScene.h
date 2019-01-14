#ifndef STORYSCENE_H
#define STORYSCENE_H

/**
 * @file StoryScene.h
 * @brief Header for the StoryScene class
 * @author Ange Bacci
 */

#include "../Scene.h"

/**
 * @class StoryScene
 * @brief The story menu scene
 *
 * Renders the Aladinde story.
 */
class StoryScene : public Scene
{
public:
    /**
     * @brief Initializes the scene with its identifier
     * @param identifier The scene identifier
     */
    StoryScene(const std::string &identifier);

    /**
     * @copydoc Scene::update(const char &lastChar)
     *
     * Simply waits for the user to press R to return to the main menu.
     */
    void update(const char &lastChar) override;

    /**
     * @copydoc Scene::render()
     *
     * Just render Aladinde's story as two text paragraphs
     */
    Matrix render() override;
};

#endif // STORYSCENE_H

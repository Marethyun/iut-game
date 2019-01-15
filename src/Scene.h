#ifndef IUT_GAME_SCENE_H
#define IUT_GAME_SCENE_H

/**
 * @file Scene.h
 * @brief Header for the Scene class
 * @author Ange Bacci
 */

#include "Matrix.h"
#include "Cell.h"

/**
 * @class Scene
 * @brief The base class for all game scenes
 *
 * This class is used as a base class for menus and the game core.
 * Scenes are rendered and updated within the game loop, using the Game class.
 * Each Scene has its proper identifier, which is used to load or unload them from
 * the game.
 *
 * @see Game
 */
class Scene {

protected:
    /**
     * @brief The scene identifier
     */
    const std::string identifier;

public:
    /**
     * @brief The default scene constructor
     *
     * Scene is an abstract class, so this constructor must be called from the child classes.
     * This constructor initializes the identifier.
     *
     * @param identifier
     */
    Scene(const std::string &identifier);
    
    /**
     * @brief The default scene destructor
     * 
     * Required for any call to delete in child classes
     * 
     * @see Game#eraseScene()
     */
    virtual ~Scene();
    
    /**
     * Getter for the identifier
     * @return The scene @ref #identifier
     */
    const std::string &getIdentifier() const;

    /**
     * @brief Updates the scene info with the last character inputted by the user
     *
     * @see Game#start()
     *
     * @param lastChar The last character inputted
     */
    virtual void update(const char &lastChar) = 0;

    /**
     * @brief Builds a Matrix to be rendered later by the Game, using the scene info
     *
     * @see Game#start()
     * @see Game
     *
     * @return The screen Matrix
     */
    virtual Matrix render() = 0;
};

#endif

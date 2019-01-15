#ifndef IUT_GAME_GAME_H
#define IUT_GAME_GAME_H

/**
 * @file Game.h
 * @brief Header for the Game class
 * @author Ange Bacci
 */

#include <map>
#include "Matrix.h"
#include "Scene.h"

/**
 * @class Game
 * @brief Defines the game structure and core utilities
 * @see Scene
 * @see Terminal
 */
class Game {
private:

    /**
     * @brief A pointer to the only class instance
     */
    static Game* singleton;

    /**
     * @brief The default, private and only constructor
     */
    Game();

    /**
     * @brief The game scenes, identified by a string
     */
    std::map<std::string, Scene*> scenes;

    /**
     * @brief The identifier to the current loaded scene
     */
    std::string currentScene = "";

    /**
     * @brief Whether the game is running or not
     */
    bool running = false;

    /**
     * @brief Returns a pointer corresponding scene in the @ref #scenes map
     *
     * @throw GameException if the scene is not registered in the game
     * @param identifier The scene identifier
     * @return The pointer to the scene
     */
    Scene* getScene(const std::string &identifier);

public:
    /**
     * @brief Used to get the singleton class instance
     *
     * Instantiate the class if @ref #singleton contains a nullptr
     *
     * @return The pointer to the class instance
    */
    static Game* get();

    /**
     * @brief Adds a scene to the game
     *
     * @param scene A pointer to the scene
     */
    void addScene(Scene* &scene);

    /**
     * @brief Loads the scene by its identifier
     *
     * @param identifier The scene identifier
     */
    void loadScene(const std::string &identifier);

    /**
     * @brief Loads the scene by its instance
     *
     * In fact the same as @ref loadScene(const std::string &identifier), but it dynamically takes the identifier from the instance
     *
     * @see Scene
     *
     * @param scene The scene instance
     */
    void loadScene(Scene &scene);

    /**
     * @brief Deletes a scene from the game by its identifier
     *
     * @param identifier The scene identifier
     */
    void eraseScene(const std::string &identifier);

    /**
     * @brief Whether the game is running or not
     * @return true if the game is running, false otherwise
     */
    bool isRunning() const;

    /**
     * @brief Starts the game
     *
     * Contains the main loop.
     * While @ref #running is true, render the scene identified by @ref #currentScene, wait for user input and update the scene with it
     */
    void start();

    /**
     * @brief Stops the game
     *
     * Stops the game by turning @ref #running to false
     */
    void stop();
};

#endif

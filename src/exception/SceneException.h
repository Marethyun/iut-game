#ifndef IUT_GAME_SCENEEXCEPTION_H
#define IUT_GAME_SCENEEXCEPTION_H

/**
 * @file SceneException.h
 * @brief Header for the SceneException class
 * @author Ange Bacci
 */

#include "GameException.h"
#include "../Scene.h"

/**
 * @class SceneException
 * @brief An exception representing a scene error
 *
 * This class is not used at all, but i don't want to delete it
 */
class SceneException : GameException {
public:
    /**
     * @brief Initialize the exception
     *
     * @param message The exception message
     * @param scene The scene related with the exception
     */
    SceneException(const std::string &message, const Scene* &scene);

    const char* what() const noexcept override;

private:
    /**
     * @brief The scene related with the exception
     */
    const Scene* scene;
};


#endif

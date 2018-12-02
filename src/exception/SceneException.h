#ifndef IUT_GAME_SCENEEXCEPTION_H
#define IUT_GAME_SCENEEXCEPTION_H

#include "GameException.h"
#include "../Scene.h"

class SceneException : GameException {
public:
    SceneException(const std::string &message, const Scene* &scene);

    const char* what() const noexcept override;

private:
    const Scene* scene;
};


#endif

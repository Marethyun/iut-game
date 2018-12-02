#include "SceneException.h"

using namespace std;

SceneException::SceneException(const std::string &message, const Scene *&scene) : GameException(message), scene(scene) {}

const char *SceneException::what() const noexcept {
    return string("scene " + scene->getIdentifier() + ": " + message).c_str();
}

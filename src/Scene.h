#ifndef IUT_GAME_SCENE_H
#define IUT_GAME_SCENE_H

#include "Matrix.h"
#include "Cell.h"

class Scene {

protected:
    const std::string identifier;

public:
    Scene(const std::string &identifier);

    const std::string &getIdentifier() const;

    // Update the game info with inputs
    virtual void update() = 0;

    // Renders the game matrix on the terminal
    virtual void render() = 0;

};

#endif

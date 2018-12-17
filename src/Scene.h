#ifndef IUT_GAME_SCENE_H
#define IUT_GAME_SCENE_H

#include "CellMatrix.h"
#include "Cell.h"

class Scene {

protected:
    const std::string identifier;

    const unsigned height;
    const unsigned width;

    CellMatrix<Cell> stageMatrix;

public:
    Scene(const unsigned int &height, const unsigned int &width, const std::string &identifier);

    const std::string &getIdentifier() const;
    unsigned int getHeight() const;
    unsigned int getWidth() const;

    // Update the game info with inputs
    // TODO: Implement an input buffer (retrieved inputs since the last frame)
    virtual void update() = 0;

    // Renders the game CellMatrix on the terminal
    virtual void render() = 0;

};

#endif

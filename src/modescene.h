#ifndef MODESCENE_H
#define MODESCENE_H

#include "Scene.h"

class ModeScene : public Scene
{
public:
    ModeScene(const std::string &identifier);

    void update(const char &lastInput);

    Matrix render();
};

#endif // MODESCENE_H

#ifndef DIFFICULTYSCENE_H
#define DIFFICULTYSCENE_H

#include "../Scene.h"

class DifficultyScene : public Scene
{
public:
    DifficultyScene(const std::string &identifier);
    
    void update(const char &lastChar) override;
    
    Matrix render() override;
};

#endif // DIFFICULTYSCENE_H

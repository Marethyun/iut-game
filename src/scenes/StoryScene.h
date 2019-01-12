#ifndef STORYSCENE_H
#define STORYSCENE_H

#include "../Scene.h"

class StoryScene : public Scene
{
public:
    StoryScene(const std::string &identifier);
    
    void update(const char &lastChar) override;
    
    Matrix render() override;
};

#endif // STORYSCENE_H

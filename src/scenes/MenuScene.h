#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../Scene.h"

class MenuScene : public Scene
{
public:
    MenuScene(const std::string &identifier);
    
    void update(const char &lastChar) override;
    
    Matrix render() override;
};

#endif // MENUSCENE_H

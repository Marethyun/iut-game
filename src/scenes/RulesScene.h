#ifndef RULESSCENE_H
#define RULESSCENE_H

#include "../Scene.h"

class RulesScene : public Scene
{
public:
    RulesScene(const std::string &identifier);
    
    void update(const char &lastChar) override;
    
    Matrix render() override;
};

#endif // RULESSCENE_H

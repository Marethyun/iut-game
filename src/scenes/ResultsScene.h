#ifndef RESULTSSCENE_H
#define RESULTSSCENE_H

#include "../Scene.h"
#include "../Difficulty.h"

class ResultsScene : public Scene
{
public:
    ResultsScene(const std::string &identifier, const unsigned &steps, const Difficulty &originalDifficulty);
    
    void update(const char &lastChar) override;
    
    Matrix render() override;
private:
    const unsigned steps = 0;
    Difficulty originalDifficulty;
};

#endif // RESULTSSCENE_H

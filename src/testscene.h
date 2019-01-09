#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <string>
#include "Matrix.h"
#include "Scene.h"
#include "Color.h"

class TestScene : public Scene {
private:
    Location playerLocation;
    Matrix matrix;
    
public:
    TestScene(const std::string &identifier);
    
    void update(const char &lastInput);
    
    Matrix render();
};
#endif // TESTSCENE_H

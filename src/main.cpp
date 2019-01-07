#include <iostream>
#include <string>

#include "testscene.h"
#include "Scene.h"
#include "Game.h"
#include "Color.h"
#include "Terminal.h"

#include <unistd.h>

using namespace std;


int main() {
        
//    Game* game = Game::get();
//    TestScene s = TestScene("Hello");
//    Scene* scene = &s;
    
//    game->addScene(scene);
//    game->loadScene(*scene);
//    game->start();
    
    Matrix m(30, 20, Cell(Color::bg_red));
    
    for (;;){
        Terminal::clear();
        Terminal::matrix(m);
    
        char c = Terminal::getch();
        if (c == 'q') break;
    }
    return 0;
}

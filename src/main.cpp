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
        
    Game* game = Game::get();
    TestScene s = TestScene("Hello");
    Scene* scene = &s;
    
    game->addScene(scene);
    game->loadScene(*scene);
    game->start();
    
//    Matrix m(5, 5, Cell(Color::bg_red, 'x'));
//    m.merge(0, 0, Cell('O'));
//    m.merge(4, 4, Cell('P'));
//    for(;;){
//        Terminal::clear();
//        Terminal::matrix(m);
        
//        char c = Terminal::getch();
//        if (c == 'q') break;
//    }
    
    
    return 0;
}

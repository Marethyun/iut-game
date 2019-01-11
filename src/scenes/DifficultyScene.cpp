#include "DifficultyScene.h"

#include "../Color.h"
#include "../Game.h"

DifficultyScene::DifficultyScene(const std::string &identifier) : Scene(identifier) {
    
}

void DifficultyScene::update(const char &c) {
    if (c == 'r') Game::get()->loadScene("main_menu");
}

Matrix DifficultyScene::render() {

    Matrix global(20, 40, Cell(Color::bg_white));

    global.text(3, 2, 34, Color::black, "Choisissez une difficulte:");

    Matrix easy(1, 25, Cell());
    easy.text(0, 0, Color::black, "- Facile (11x11)");
    easy.text(easy.getWidth() - 3, 0, Color::black, "<A>");

    Matrix normal(1, 25, Cell());
    normal.text(0, 0, Color::black, "- Normal (21x21)");
    normal.text(normal.getWidth() - 3, 0, Color::black, "<B>");

    Matrix hard(1, 25, Cell());
    hard.text(0, 0, Color::black, "- Difficile (31x31)");
    hard.text(hard.getWidth() - 3, 0, Color::black, "<C>");

    global.merge(5, 5, easy);
    global.merge(5, 6, normal);
    global.merge(5, 7, hard);


    return global;
}

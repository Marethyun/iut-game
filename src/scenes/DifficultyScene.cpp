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

    Matrix easy(1, 30, Cell());
    easy.text(0, 0, Color::black, "A - Facile");
    easy.text(easy.getWidth() - 7, 0, Color::black, "(11x11)");

    Matrix normal(1, 30, Cell());
    normal.text(0, 0, Color::black, "B - Normal");
    normal.text(normal.getWidth() - 7, 0, Color::black, "(21x21)");

    Matrix hard(1, 30, Cell());
    hard.text(0, 0, Color::black, "C - Difficile");
    hard.text(hard.getWidth() - 7, 0, Color::black, "(41x41)");

    Matrix phasianidae(1, 30, Cell());
    phasianidae.text(0, 0, Color::black, "D - Phasianidae");
    phasianidae.text(phasianidae.getWidth() - 9, 0, Color::black, "(101x101)");

    Matrix back(1, 30, Cell());
    back.text(0, 0, Color::black, "R - Retour au menu");

    global.merge(5, 5, easy);
    global.merge(5, 6, normal);
    global.merge(5, 7, hard);
    global.merge(5, 8, phasianidae);
    global.merge(5, 10, back);

    global.text(3, 13, Color::black, "Le saviez-vous?");

    global.text(1, 15, 38, Color::black, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");


    return global;
}

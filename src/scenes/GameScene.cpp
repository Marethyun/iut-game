#include "GameScene.h"
#include "../Color.h"
#include "../Game.h"
#include <math.h>
#include <sstream>

using namespace std;

GameScene::GameScene(const std::string &identifier, const Map &gameMap, const unsigned &difficulty) : 
    Scene(identifier), 
    gameMap(gameMap),
    totalKeys(gameMap.remainingKeys()),
    player(Player(gameMap.getBegin(), Cell(Color::bold + Color::yellow, '&'), 2)),
    difficulty(difficulty),
    constraintVision(gameMap.isGrass(gameMap.getBegin())),
    lastNote("Aladinde: ...") {
}

void GameScene::update(const char &c) {
    
    Location nextLocation = this->player.getLocation();
    
    switch (c) {
        case 'z':
        case 'Z':
            nextLocation.setY(nextLocation.getY() - 1);
            break;
        case 'q':
        case 'Q':
            nextLocation.setX(nextLocation.getX() - 1);
            break;
        case 's':
        case 'S':
            nextLocation.setY(nextLocation.getY() + 1);
            break;
        case 'd':
        case 'D':
            nextLocation.setX(nextLocation.getX() + 1);
    }
    
    if (gameMap.isWall(nextLocation) || !gameMap.getMap().isInBounds(nextLocation)) {
        return;
    }
    
    if (this->gameMap.isKey(nextLocation)) {
        this->gameMap.claimKey(nextLocation);
        ++this->claimedKeys;
        if (this->claimedKeys == this->totalKeys) exitOpened = true;
        
        this->lastNote = "Aladinde: Glou.. Une clef.";
    }
    
    this->constraintVision = this->gameMap.isGrass(nextLocation);
    
    if (this->gameMap.isObject(nextLocation)) {
        srand(time(NULL));
        
        bool goodObject = rand() % 2 == 0;
        
        if (goodObject) {
            if (this->player.getVision() < 6) {
                this->player.setVision(this->player.getVision() + 1);
                this->lastNote = "Aladinde: Glouglou ! (+1)";
            }
        } else {
            if (this->player.getVision() > 1) {
                this->player.setVision(this->player.getVision() - 1);
                this->lastNote = "Aladinde: Gl..Eeek !? (-1)";
            }
        }
        
        this->gameMap.claimObject(nextLocation);
    }
    
    this->player.setLocation(nextLocation);
    ++stepsCount;

}

Matrix GameScene::render() {
    
    unsigned gameWidth = 55;
    
    unsigned currentVision = this->constraintVision ? 1 : this->player.getVision();
    
    // crop coordinates
    int topX = player.getLocation().getX() - (int) currentVision;
    int topY = player.getLocation().getY() - (int) currentVision;
    
    int botX = player.getLocation().getX() + (int) currentVision;
    int botY = player.getLocation().getY() + (int) currentVision;
    
    Location top(topX, topY);
    Location bottom(botX, botY);
    
    // Map qui va être modifiée avec les modificateurs courants
    Matrix alteredMap = this->gameMap.getMap();
    
    if (this->exitOpened) alteredMap.replace(this->gameMap.getEnd(), Cell(Color::bg_green, '@'));
    
    Matrix croppedView = alteredMap.crop(top, bottom, Cell('?'));
    
    croppedView.merge(croppedView.center(), this->player.getAppearance());
    
    Matrix gameSlot(13, gameWidth, Cell());
    
    Location gameSlotCenter = gameSlot.center();
    
    Location croppedViewPos(gameSlotCenter.getX() - currentVision, gameSlotCenter.getY() - currentVision);
    
    gameSlot.replace(croppedViewPos, croppedView);
    
    Matrix head(1, gameWidth, Cell(Color::bg_red + Color::black));
    
    ostringstream oss;
    oss << "Vision: " << currentVision;
    head.text(head.getWidth() - 9, 0, Color::white, oss.str());
    oss.str(std::string());
    oss << "Coups: " << this->stepsCount;
    head.text(head.getWidth() - 21, 0, Color::white, oss.str());
    oss.str(std::string());
    // TODO CHANGER DIFFICULT
    oss << "Ferme Facile (" << this->gameMap.getMap().getWidth() << "x" << this->gameMap.getMap().getHeight() << ")";
    head.text(0, 0, Color::white, oss.str());
    oss.str(std::string());
    
    Matrix foot(1, gameWidth, Cell(Color::bg_red + Color::black));
    
    foot.text(0, 0, Color::white, this->lastNote);
    
    if (this->lastNote.size() != 0) {
        this->lastNote = "Aladinde: ...";
    }
    
    oss << "Porte " << (this->exitOpened ? "ouverte" : "fermee") << " (clefs: " << this->claimedKeys << "/" << this->totalKeys << ")";
    foot.text(foot.getWidth() - oss.str().size(), 0, Color::white, oss.str());
    
    Matrix global(head.getHeight() + gameSlot.getHeight() + foot.getHeight(), gameWidth, Cell());
    
    global.replace(0, 0, head);
    global.replace(0, head.getHeight(), gameSlot);
    global.replace(0, head.getHeight() + gameSlot.getHeight(), foot);
    
    return global;
}

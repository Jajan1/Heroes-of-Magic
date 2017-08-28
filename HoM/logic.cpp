#include "logic.h"
#include <QPoint>
#include <QDebug>

Logic::Logic()
{
    player = NULL;
    enemy = NULL;
}

void Logic::update()
{
    player->execMods();
    enemy->execMods();
}

QPoint Logic::playerPos(){
    if (player != NULL){
        return player->currentPos();
    }
    else return QPoint(0,0);
}

QPoint Logic::enemyPos(){
    if (player != NULL){
        return enemy->currentPos();
    }
    else return QPoint(0,0);
}

Spell *Logic::getSpellPointer(int number)
{
    if (player != NULL){
        return player->getSpellPointer(number);
    } else
        return NULL;
}

bool Logic::spellCreated(int number)
{
    if (player != NULL){
        return player->spellCreated(number);
    } else
        return 0;
}

int Logic::playerCreated()
{
    FireMage *f = dynamic_cast<FireMage*> (player);
    if (f){
        return 1;
    } else
        return 0;
}

int Logic::enemyCreated()
{
    FireMage *f = dynamic_cast<FireMage*> (enemy);
    if (f){
        return 1;
    } else
        return 0;
}

void Logic::createFiremage()
{
    if (player == NULL){
        player = new FireMage(QPoint(100,250));
    } else if (enemy == NULL){
        enemy = new FireMage(QPoint(600,250));
    }
}

void Logic::movePlayer(int direction)
{
    if (player != NULL){
        switch (direction){

        case 0: //left
            player->moveLeft();
            break;

        case 1: //right
            player->moveRight();
            break;

        case 2: //up
            player->moveUp();
            break;

        case 3: //down
            player->moveDown();
            break;
        }
    }
}

void Logic::castSpell(uint number)
{
    player->castSpell(number);
}

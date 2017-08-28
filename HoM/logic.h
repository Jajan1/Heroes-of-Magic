#ifndef LOGIC_H
#define LOGIC_H


#include "interface.h"
#include "hero.h"

class Logic : public Interface
{
public:
    Logic();
    void update();
    QPoint playerPos();
    QPoint enemyPos();
    Spell* getSpellPointer(int number);
    bool spellCreated(int number);
    int playerCreated();
    int enemyCreated();
    void createFiremage();
    void movePlayer(int direction);
    void castSpell(uint number);

private:
    Hero *player;
    Hero *enemy;
};

#endif // LOGIC_H

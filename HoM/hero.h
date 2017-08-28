#ifndef HERO_H
#define HERO_H

#include "attribute.h"
#include "spell.h"
#include <deque>
#include <QPoint>

using namespace std;

class Hero
{
public:
    Hero();
    virtual void execMods();
    void addEffect(Effect *effect);
    void removeEffect();
    void checkDead();
    QPoint currentPos();
    void castSpell(uint number);
    bool spellCreated(uint number);
    Spell* getSpellPointer(uint number);
    Attribute *getAttributePointer(uint number);
    void makeInvisible();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

protected:
    deque <Spell*> spells;
    deque <Attribute*> attributes;
    deque <Effect*> effects;
    QPoint position;
    bool isInvisible=0;
};

//definicje czarodziejów

class FireMage : public Hero
{
public:
    FireMage(QPoint pos);
};

#endif // HERO_H

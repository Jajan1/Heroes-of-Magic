#ifndef EFFECT_H
#define EFFECT_H

#include <deque>
#include "attribute.h"

class Hero;

using namespace std;

class Effect
{
public:
    Effect();
    virtual void execMods(Hero *hero);

protected:
    int duration;
    int power;
};

//poszczególne efekty

class Damage : public Effect
{
public:
    Damage(Attribute *onattr);
    void execMods(Hero *hero);

private:
    int value;
    bool isPercent;
    Attribute *onAttribute;
};

#endif // EFFECT_H

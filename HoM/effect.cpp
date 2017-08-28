#include "effect.h"
#include "hero.h"


Effect::Effect()
{

}

void Effect::execMods(Hero *hero)
{

}

Damage::Damage(Attribute *onattr)
{
    value = -10;
    isPercent = false;
    onAttribute = onattr;
    duration = 1;
    power = 1;
}

void Damage::execMods(Hero *hero)
{
    if (duration == 0){
        hero->removeEffect();
        return;
    } else if (isPercent){
        onAttribute->setValueByPercent(value);
    } else {
        onAttribute->setValueBy(value);
    }
    duration--;
}

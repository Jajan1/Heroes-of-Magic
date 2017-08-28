#include "hero.h"
#include <QKeyEvent>
#include <QApplication>

#include <QDebug>


Hero::Hero()
{

}

void Hero::execMods()
{
    qDebug() << "HP:" << attributes[0]->currentValue();
    for (unsigned int i=0; i<effects.size(); i++){
        qDebug() << "Executing effect:" << i;
        effects[i]->execMods(this);
    }
}

void Hero::addEffect(Effect *effect)
{
    effects.push_back(effect);
}

void Hero::removeEffect() //argument wskaźnik na efekt ktory ma byc usuniety
{
    effects.pop_front();
}

void Hero::checkDead()
{
    if (attributes[0]->currentValue() == 0){
        qDebug() << "Dead hero found";
        qDebug() << "Game Over";
        QApplication::quit();
    }
}

QPoint Hero::currentPos()
{
    return position;
}

void Hero::castSpell(uint number)
{
    if (number < spells.size()){
        spells[number]->exec(this);
    }
}

bool Hero::spellCreated(uint number)
{
    if (number < spells.size()){
        return spells[number]->created();
    } else
        return 0;
}

Spell *Hero::getSpellPointer(uint number)
{
    if (number < spells.size()){
        return spells[number];
    } else
        return NULL;
}

Attribute *Hero::getAttributePointer(uint number)
{
    if (number < attributes.size()){
        return attributes[number];
    } else
        return NULL;
}

void Hero::makeInvisible()
{
    isInvisible = true;
}

void Hero::moveLeft()
{
    if (position.x() > 0){
        position += QPoint(-10,0);
    }
}

void Hero::moveRight()
{
    if (position.x() < 700) {
        position += QPoint(10,0);
    }
}

void Hero::moveUp()
{
    if (position.y() > 0){
        position += QPoint(0,-10);
    }
}

void Hero::moveDown()
{
    if (position.y() < 500){
        position += QPoint(0,10);
    }
}

// poszczególni magowie

FireMage::FireMage(QPoint pos)
{
    // add spells to the list
    FireBall *fb = new FireBall;
    Mirror *mi = new Mirror;
    Invisibility *inv = new Invisibility;
    spells.push_back(fb);
    spells.push_back(mi);
    spells.push_back(inv);

    // add attributes to the list
    Attribute *hp = new HP();
    Attribute *mp = new MP();
    Attribute *unik = new Dodge();
    Attribute *odpornosc = new Resistance();
    attributes.push_back(hp);
    attributes.push_back(mp);
    attributes.push_back(unik);
    attributes.push_back(odpornosc);

    //starting position
    position = pos;
}

#include "spell.h"
#include <QDebug>
#include "hero.h"
#include <typeinfo>
#include <QTimer>

Spell::Spell()
{

}

void Spell::exec(Hero *target)
{

}

bool Spell::created()
{
    return isCreated;
}

QPoint Spell::currentPos()
{
    return position;
}

//      FireBall

FireBall::FireBall()
{

}

void FireBall::exec(Hero *target)
{
    isCreated = 1;
    qDebug() << "Fireball created";

    position = QPoint(target->currentPos().x() + 100, target->currentPos().y());

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move(target)));

    timer->start(50);
}

void FireBall::enemyHit(Hero *target)
{
    effect = new Damage(target->getAttributePointer(0));
}

void FireBall::move(Hero *target)
{
    position += QPoint(10,0);

    if (position.x() > 600 && position.x() < 700
            && position.y() > 250 && position.y() < 350){
        enemyHit(target);
    }
}

//      Mirror

Mirror::Mirror()
{

}

void Mirror::exec(Hero *target)
{
    isCreated = 1;
    qDebug() << "Mirror created";

    position = QPoint(target->currentPos().x(), target->currentPos().y() - 150);
}

//      Invisibility

Invisibility::Invisibility()
{

}

void Invisibility::exec(Hero *target)
{
    isCreated = 1;
    qDebug() << "Invisibility created";

    target->makeInvisible();
}

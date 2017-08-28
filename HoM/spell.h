#ifndef SPELL_H
#define SPELL_H

#include <QPoint>
#include <QObject>
#include "attribute.h"
#include "effect.h"

class Spell
{
public:
    Spell();
    virtual void exec(Hero *target);
    bool created();
    QPoint currentPos();

protected:
    Effect *effect;
    bool isCreated = 0;
    QPoint position;
};

//poszczególne czary

class FireBall : public QObject, public Spell
{
    Q_OBJECT
public:
    FireBall();
    void exec(Hero *target);

private:
    void enemyHit(Hero *target);

public slots:
    void move(Hero *target);
};

class Mirror : public Spell
{
public:
    Mirror();
    void exec(Hero *target);
};

class Invisibility : public Spell
{
public:
    Invisibility();
    void exec(Hero *target);
};

#endif // SPELL_H

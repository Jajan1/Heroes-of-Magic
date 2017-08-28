#include "gspell.h"

GSpell::GSpell(int number)
{
    switch (number){

    case 0:
        drawFireball();
        break;

    case 1:
        drawMirror();
        break;

    case 2:
        drawInvisibility();
        break;
    }
}

void GSpell::pointAtSpell(Spell *pointer)
{
    spell = pointer;
}

void GSpell::drawFireball()
{
    setPixmap(QPixmap(":/fireball.png"));
}

void GSpell::drawMirror()
{
    setPixmap(QPixmap(":/fire_mage.png"));
}

void GSpell::drawInvisibility()
{
    setPixmap(QPixmap(""));
}

void GSpell::redraw()
{
    setPos(spell->currentPos());
}

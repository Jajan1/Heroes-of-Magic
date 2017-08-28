#ifndef GSPELL_H
#define GSPELL_H

#include <QGraphicsPixmapItem>
#include "spell.h"

class GSpell : public QGraphicsPixmapItem
{
public:
    GSpell(int number);
    void pointAtSpell(Spell *pointer);
    void drawFireball();
    void drawMirror();
    void drawInvisibility();
    void redraw();

private:
    Spell *spell;
};

#endif // GSPELL_H

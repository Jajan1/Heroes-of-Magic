#include "ghero.h"
#include "spell.h"

#include <QGraphicsScene>
#include <QDebug>

GHero::GHero()
{

}

void GHero::createFiremage()
{
    // draw Fire Mage
    setPixmap(QPixmap(":/fire_mage.png"));
}

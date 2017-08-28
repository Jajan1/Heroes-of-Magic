#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QObject>
#include <deque>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include "logic.h"
#include "ghero.h"
#include "gspell.h"

using namespace std;

class Graphics : public QGraphicsView
{
    Q_OBJECT
public:
    Graphics();
    void logicPointer(Logic *pointer);
    void heroselect();
    void keyPressEvent(QKeyEvent * event);

private:
    Logic *logic;
    QTimer *timer;
    GHero *gplayer;
    GHero *genemy;
    deque <GSpell*> spells;

    QGraphicsScene *scene;
    QGraphicsTextItem *heroselection;
    QGraphicsTextItem *spell_list;

public slots:
    void update();
};

#endif // GRAPHICS_H

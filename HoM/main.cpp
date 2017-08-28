#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "graphics.h"
#include "logic.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logic *logic = new Logic;
    Graphics *graphics = new Graphics;
    graphics->logicPointer(logic);
    graphics->show();
    return a.exec();
}

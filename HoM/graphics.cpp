#include "graphics.h"
#include <QTimer>
#include <QDebug>


Graphics::Graphics()
{
    gplayer = NULL;
    genemy = NULL;

    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QImage background(":/windows_xp_tapeta.jpg");
    setBackgroundBrush(QBrush(background.scaled(800,600)));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // hero selection
    heroselect();

    // create a timer to update the game
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(500);
}

void Graphics::logicPointer(Logic *pointer)
{
    logic = pointer;
}

void Graphics::heroselect()
{
    qDebug() << "Attempting heroselection";
    // draw the text
    heroselection = new QGraphicsTextItem;
    heroselection->setPlainText(QString("FireMage press: f")); // wybór FireMage
    heroselection->setDefaultTextColor(Qt::blue);
    heroselection->setFont(QFont("times",14));
    scene->addItem(heroselection);
}

void Graphics::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F){
        qDebug()<<"F button pressed";
        logic->createFiremage();
    } else if (event->key() == Qt::Key_Left){
            logic->movePlayer(0);
        }
        else if (event->key() == Qt::Key_Right){
            logic->movePlayer(1);
        }
        else if (event->key() == Qt::Key_Up){
            logic->movePlayer(2);
        }
        else if (event->key() == Qt::Key_Down){
            logic->movePlayer(3);
        }
        else if (event->key() == Qt::Key_1){
            logic->castSpell(0);
        }
        else if (event->key() == Qt::Key_2){
            logic->castSpell(1);
        }
        else if (event->key() == Qt::Key_3){
            logic->castSpell(2);
        }
}

void Graphics::update()
{
    qDebug()<< "Timer update";

    // checking if the players were chosen
    if (logic->playerCreated() == 1 && gplayer == NULL){
        gplayer = new GHero;
        gplayer->createFiremage();
        scene->addItem(gplayer);
    }
    if (logic->enemyCreated() == 1 && genemy == NULL){
        genemy = new GHero;
        genemy->createFiremage();
        scene->addItem(genemy);
        scene->removeItem(heroselection);
    }

    // hero positions
    if (gplayer != NULL){
        gplayer->setPos(logic->playerPos());
    }
    if (genemy != NULL){
        genemy->setPos(logic->enemyPos());
    }

    // checking if any spells were created
    for (int i = 0; i < 3; i++){
        if (logic->spellCreated(i)){
            GSpell *currentSpell = new GSpell(i);
            currentSpell->pointAtSpell(logic->getSpellPointer(i));
            spells.push_back(currentSpell);
        }
    }

    // redraw all spells at updated position
    for (uint i = 0; i < spells.size(); i++){
        spells[i]->redraw();
    }

    logic->update();
}

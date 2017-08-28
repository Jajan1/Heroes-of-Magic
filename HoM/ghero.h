#ifndef GHERO_H
#define GHERO_H

#include <QGraphicsPixmapItem>
#include <deque>


class GHero : public QGraphicsPixmapItem
{
public:
    GHero();
    void createFiremage();
};

#endif // GHERO_H

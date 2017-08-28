#include "view.h"

#include <QtWidgets>
#include <qmath.h>

View::View(const QString &name, QWidget *parent)
    : QFrame(parent)
{
    setFrameStyle(Sunken | StyledPanel);
    graphicsView = new GraphicsView(this);

    graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);

    // Label layout
    QHBoxLayout *labelLayout = new QHBoxLayout;
    label = new QLabel(name);

    labelLayout->addWidget(label);
    labelLayout->addStretch();
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addLayout(labelLayout, 0, 0);
    topLayout->addWidget(graphicsView, 1, 0);
    setLayout(topLayout);

}

View::~View(){

}

QGraphicsView *View::view() const
{
    return static_cast<QGraphicsView *>(graphicsView);
}

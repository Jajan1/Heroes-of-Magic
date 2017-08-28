#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view.h"

#include <QHBoxLayout>
#include <QSplitter>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    QWidget *centralWidget;

    View *view = new View("Gra Janka");
    populateScene(); //NIŻEJ
    view->view()->setScene(scene);

    centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );

    QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    layout->addWidget(view);
//    setLayout(layout); //QWidget::setLayout: Attempting to set QLayout "" on MainWindow "MainWindow", which already has a layout

    setWindowTitle(tr("HoM"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateScene()
{
    scene = new QGraphicsScene;

    QImage image(":/qt4logo.png");

    // Tło mapy
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(QPixmap(":/windows_xp_tapeta.jpg"));
    background->setPos(-148,-83);
    background->setScale(0.8); //POMNIEJSZA OBRAZEK 0.8 RAZA
    background->scale();
    scene->addItem(background);
    //**


}

#include "mainwindow.hpp"
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qlabel.h>
#include <qslider.h>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Potato Player");
    QWidget *main = new QWidget();
    this->setCentralWidget(main);

    QMenu *fileMenu = menuBar()->addMenu("&Fichier");
    QMenu *playMenu = menuBar()->addMenu("&Lecture");
    QMenu *viewMenu = menuBar()->addMenu("&Affichage");

    QAction *quitAction = new QAction("&Quitter",this);
    fileMenu->addAction(quitAction);
    QObject::connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));


    QAction *playAction = new QAction(QIcon(":/icons/icons/control_play_blue.png"),"Lire",this);
    playMenu->addAction(playAction);

    QAction *pauseAction = new QAction(QIcon(":/icons/icons/control_pause_blue.png"),"Pause",this);
    playMenu->addAction(pauseAction);

    QAction *stopAction = new QAction(QIcon(":/icons/icons/control_stop_blue.png"),"Arrêter",this);
    playMenu->addAction(stopAction);

    QAction *prevAction = new QAction(QIcon(":/icons/icons/control_start_blue.png"),"Précédent",this);
    playMenu->addAction(prevAction);

    QAction *nextAction = new QAction(QIcon(":/icons/icons/control_end_blue.png"),"Suivant",this);
    playMenu->addAction(nextAction);

    QAction *repeatAction = new QAction(QIcon(":/icons/icons/control_repeat_blue.png"),"Répéter",this);
    repeatAction->setCheckable(true);
    playMenu->addAction(repeatAction);


    QToolBar *playToolbar = this->addToolBar("Lecture");
    playToolbar->setMovable(false);
    playToolbar->addAction(playAction);
    playToolbar->addAction(pauseAction);
    playToolbar->addAction(stopAction);
    playToolbar->addAction(prevAction);
    playToolbar->addAction(nextAction);
    playToolbar->addSeparator();
    QLabel *songTitle = new QLabel("  Titre de la chanson - Artiste  ");
    QSlider *songSlider = new QSlider(Qt::Horizontal);
    playToolbar->addWidget(songTitle);
    playToolbar->addWidget(songSlider);
    playToolbar->addSeparator();
    playToolbar->addAction(repeatAction);

    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("/home/nyx/mario8bit.mp3"));
    QObject::connect(playAction,SIGNAL(triggered()),player,SLOT(play()));
    QObject::connect(pauseAction,SIGNAL(triggered()),player,SLOT(pause()));
}

MainWindow::~MainWindow()
{

}

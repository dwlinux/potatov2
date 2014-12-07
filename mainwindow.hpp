#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QtGui>
#include <QMediaPlayer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMediaPlayer *player;
    QAction *playAction;
    QAction *pauseAction;
    QAction *stopAction;
    QAction *prevAction;
    QAction *nextAction;
    QAction *repeatAction;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setPlay(void);
};

#endif // MAINWINDOW_HPP

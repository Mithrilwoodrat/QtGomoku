#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPointer>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include "gomoku.h"
#include "serverdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void drawBoard();
    void drawPieces();
    void drawPiece(Qt::GlobalColor, int i, int j);
private:
    enum {w_width=660, w_height=660,/* windows width and height*/
          b_width=600, b_height=600};/*board width and height*/
    static const int boardstart = 30;/*(windows size - board size)/2*/
    static const int boardend = 630;/* windows size - (windows size - board size)/2*/
    static const int spacer = 40; /* boardwith / boardsize*/
    Gomoku game;
    QPainter painter;
    void createActions();
    void createMenus();
    QMenu * fileMenu;
    QMenu * helpMenu;
    QAction *newAct;
    QAction *serverAct;
    QAction *clientAct;
    QAction *setPAct;
    QAction *exitAct;
    ServerDialog * serverDialog;

protected:
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void newGame();
    void setDefaultPlayer();
    void workAsServer();
    void workAsClient();
};

#endif // MAINWINDOW_H

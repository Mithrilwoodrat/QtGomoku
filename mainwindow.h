#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPointer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int isgameEnd(int x, int y);
    int isp1Win(int x, int y);
    int isp2Win(int x, int y);
    void drawBoard();
    void drawPieces();
    void drawPiece(Qt::GlobalColor, int i, int j);
private:
    enum {w_width=640, w_height=640,/* windows width and height*/
          b_width=600, b_height=600};/*board width and height*/
    static const int boardsize = 15;
    int checkerboard[boardsize][boardsize];
    int current_player;
    int last_player;
    enum playerlist {player1=1,player2=2};
    static const int boardstart = 20;/*(windows size - board size)/2*/
    static const int boardend = 620;/* windows size - (windows size - board size)/2*/
    static const int spacer = 40; /* boardwith / boardsize*/
    QPainter painter;
protected:
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H

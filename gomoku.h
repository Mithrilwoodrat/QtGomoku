#ifndef GOMOKU_H
#define GOMOKU_H

#include <string.h>
#include <QVector>
class Gomoku
{
public:
    explicit Gomoku();
    ~Gomoku();
    void initBoard();
    int isgameEnd(int x, int y);
    int isWin(int x, int y);
    int isPiece(int x, int y);
    void putPiece(int x, int y);
    void switchPlayer();
protected:
    static const int boardsize = 15;
    QVector<QVector<int> > board;
    int current_player;
    int last_player;
    int endFlag;
    enum playerlist {player1=1,player2=2};
};

#endif // GOMOKU_H

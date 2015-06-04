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
    int isgameEnd() const;
    int isWin(int x, int y) const;
    int isPiece(int x, int y) const;
    int getPiece(int x, int y) const;
    void putPiece(int x, int y);
    void switchPlayer();
    static const int boardsize = 15;
    enum playerlist {player1=1,player2=2};
    int getLast_player() const;
    void setEndFlag();

protected:
    QVector<QVector<int> > board;
    int current_player;
    int last_player;
    int endFlag;
};

#endif // GOMOKU_H

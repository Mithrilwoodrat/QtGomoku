#include "gomoku.h"

Gomoku::Gomoku():board(boardsize,QVector<int>(boardsize,0)),current_player(player1),endFlag(0)
{
}

Gomoku::~Gomoku()
{

}

/* 默认黑色先走,设置player1先走,颜色为黑.*/
void Gomoku::initBoard()
{
    board = QVector<QVector<int > >(boardsize, QVector<int>(boardsize, 0));
    current_player = player1;
    endFlag = 0;
}

/* 指定位置有无棋子*/
int Gomoku::isPiece(int x, int y) const
{
    return board[x][y];
}

/* 返回指定位置的棋子的颜色 */
int Gomoku::getPiece(int x, int y) const
{
    return board[x][y];
}

void Gomoku::putPiece(int x, int y)
{
    board[x][y] = current_player;
}

void Gomoku::switchPlayer()
{
    last_player = current_player;
    current_player = current_player==player1?player2:player1;
}

int Gomoku::getLast_player() const
{
    return last_player;
}

void Gomoku::setEndFlag()
{
    endFlag = 1;
}


int Gomoku::isgameEnd() const
{
    return endFlag;
}

int Gomoku::isWin(int x, int y) const
{
    int i;
    for(i=0;i<5;i++)
    {
        if(y - i >= 0 &&
           y + 4 - i < boardsize &&
           board[x][y - i] == board[x][y + 1 - i] &&
           board[x][y - i] == board[x][y + 2 - i] &&
           board[x][y - i] == board[x][y + 3 - i] &&
           board[x][y - i] == board[x][y + 4 - i])
        return 1;
        if(x - i >= 0 &&
             x + 4 - i < boardsize &&
             board[x - i][y] == board[x + 1 - i][y] &&
             board[x - i][y] == board[x + 2 - i][y] &&
             board[x - i][y] == board[x + 3 - i][y] &&
             board[x - i][y] == board[x + 4 - i][y])
        return 1;
        if(x - i >= 0 &&
           y - i >= 0 &&
           x + 4 - i < boardsize &&
           y + 4 - i < boardsize &&
           board[x - i][y - i] == board[x + 1 - i][y + 1 - i] &&
           board[x - i][y - i] == board[x + 2 - i][y + 2 - i] &&
           board[x - i][y - i] == board[x + 3 - i][y + 3 - i] &&
           board[x - i][y - i] == board[x + 4 - i][y + 4 - i])
           return 1;
        if(x + i < boardsize &&
                   y - i >= 0 &&
                   x - 4 + i >= 0 &&
                   y + 4 - i < boardsize &&
                   board[x + i][y - i] == board[x - 1 + i][y + 1 - i] &&
                   board[x + i][y - i] == board[x - 2 + i][y + 2 - i] &&
                   board[x + i][y - i] == board[x - 3 + i][y + 3 - i] &&
                   board[x + i][y - i] == board[x - 4 + i][y + 4 - i])
           return 1;
    }
    return 0;
}

#include "gomoku.h"

Gomoku::Gomoku():board(boardsize,QVector<int>(boardsize,0)),current_player(player1),endFlag(0)
{
}

Gomoku::~Gomoku()
{

}
/* default black is first so player1 is black*/
void Gomoku::initBoard()
{
    current_player = player1;
    endFlag = 0;
}

int Gomoku::isPiece(int x, int y)
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

int Gomoku::isgameEnd(int x, int y)
{
    if (isWin(x,y))
        endFlag = 1;
    else
        endFlag = 0;
    return endFlag;
}
int Gomoku::isWin(int x, int y)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(y - i >= 0 &&
           y + 4 - i <= 15 &&
           board[x][y - i] == board[x][y + 1 - i] &&
           board[x][y - i] == board[x][y + 2 - i] &&
           board[x][y - i] == board[x][y + 3 - i] &&
           board[x][y - i] == board[x][y + 4 - i])
        return 1;
        if(x - i >= 0 &&
             x + 4 - i <= 15 &&
             board[x - i][y] == board[x + 1 - i][y] &&
             board[x - i][y] == board[x + 2 - i][y] &&
             board[x - i][y] == board[x + 3 - i][y] &&
             board[x - i][y] == board[x + 4 - i][y])
        return 1;
        if(x - i >= 0 &&
           y - i >= 0 &&
           x + 4 - i <= 15 &&
           y + 4 - i <= 15 &&
           board[x - i][y - i] == board[x + 1 - i][y + 1 - i] &&
           board[x - i][y - i] == board[x + 2 - i][y + 2 - i] &&
           board[x - i][y - i] == board[x + 3 - i][y + 3 - i] &&
           board[x - i][y - i] == board[x + 4 - i][y + 4 - i])
           return 1;
        if(x + i <= 15 &&
                   y - i >= 0 &&
                   x - 4 + i >= 0 &&
                   y + 4 - i <= 15 &&
                   board[x + i][y - i] == board[x - 1 + i][y + 1 - i] &&
                   board[x + i][y - i] == board[x - 2 + i][y + 2 - i] &&
                   board[x + i][y - i] == board[x - 3 + i][y + 3 - i] &&
                   board[x + i][y - i] == board[x - 4 + i][y + 4 - i])
           return 1;
    }
    return 0;
}

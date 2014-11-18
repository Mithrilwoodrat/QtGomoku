#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* default black is first and player1 is black*/
    current_player = player1;
    memset(checkerboard,0,boardsize*boardsize*sizeof(int));
    setFixedSize(w_width,w_height);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    painter.begin(this);
    drawBoard();
    drawPieces();
    painter.end();
}

void MainWindow::drawBoard()
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing, true);
    int i;
    for(i=0;i<=boardsize;i++)
    {
        painter.drawLine(boardstart, boardstart + i * spacer,
                         boardend, boardstart + i * spacer);
        painter.drawLine(boardstart + i * spacer, boardstart,
                         boardstart + i * spacer, boardend);
    }
    painter.restore();
}

void MainWindow::drawPieces()
{
    painter.save();
    int i,j;
    for (i = 0; i < boardsize; i++)
    {
        for (j = 0; j < boardsize; j++)
        {
            if (checkerboard[i][j] == 1)
                drawPiece(Qt::black, i, j);
            else if (checkerboard[i][j] == 2)
                drawPiece(Qt::white, i, j);
        }
    }
    painter.restore();
}
void MainWindow::drawPiece(Qt::GlobalColor color, int i, int j)
{
    painter.save();
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if ((color == Qt::white) or (color == Qt::black))
    {
        brush.setColor(color);
        painter.setBrush(brush);
        painter.drawEllipse(QPoint((i + 1) * spacer, (j + 1) * spacer), 15, 15);
    }
    painter.restore();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int x, y;
    if(e->x() >= boardstart && e->x() < boardend &&
       e->y() >= boardstart && e->y() < boardend)
    {
        x = (e->x() - boardstart) / spacer;
        y = (e->y() - boardstart) / spacer;
        if (!checkerboard[x][y])
        {
            checkerboard[x][y] = current_player;
            last_player = current_player;
            current_player = current_player==player1?player2:player1;
        }
        if(isgameEnd(x, y))
        {
            update();
            setEnabled(false);
            QMessageBox::information(this, "Win",
                                     last_player==player1?"player1 Win":"player2 Win",
                                     QMessageBox::Ok);
        }
    }
    update();
}
int MainWindow::isgameEnd(int x, int y)
{
    return isp1Win(x,y)||isp2Win(x,y);
}
int MainWindow::isp1Win(int x, int y)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(y - i >= 0 &&
           y + 4 - i <= 15 &&
           checkerboard[x][y - i] == checkerboard[x][y + 1 - i] &&
           checkerboard[x][y - i] == checkerboard[x][y + 2 - i] &&
           checkerboard[x][y - i] == checkerboard[x][y + 3 - i] &&
           checkerboard[x][y - i] == checkerboard[x][y + 4 - i])
        return 1;
        if(x - i >= 0 &&
             x + 4 - i <= 15 &&
             checkerboard[x - i][y] == checkerboard[x + 1 - i][y] &&
             checkerboard[x - i][y] == checkerboard[x + 2 - i][y] &&
             checkerboard[x - i][y] == checkerboard[x + 3 - i][y] &&
             checkerboard[x - i][y] == checkerboard[x + 4 - i][y])
        return 1;
    }
    return 0;
}
int MainWindow::isp2Win(int x, int y)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(x - i >= 0 &&
           y - i >= 0 &&
           x + 4 - i <= 15 &&
           y + 4 - i <= 15 &&
           checkerboard[x - i][y - i] == checkerboard[x + 1 - i][y + 1 - i] &&
           checkerboard[x - i][y - i] == checkerboard[x + 2 - i][y + 2 - i] &&
           checkerboard[x - i][y - i] == checkerboard[x + 3 - i][y + 3 - i] &&
           checkerboard[x - i][y - i] == checkerboard[x + 4 - i][y + 4 - i])
           return 1;
        if(x + i <= 15 &&
                   y - i >= 0 &&
                   x - 4 + i >= 0 &&
                   y + 4 - i <= 15 &&
                   checkerboard[x + i][y - i] == checkerboard[x - 1 + i][y + 1 - i] &&
                   checkerboard[x + i][y - i] == checkerboard[x - 2 + i][y + 2 - i] &&
                   checkerboard[x + i][y - i] == checkerboard[x - 3 + i][y + 3 - i] &&
                   checkerboard[x + i][y - i] == checkerboard[x - 4 + i][y + 4 - i])
           return 1;
    }
    return 0;
}

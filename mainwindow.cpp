#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Gomoku"));
    setFixedSize(w_width,w_height);
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete newAct;
    delete setPAct;
    delete serverAct;
    delete clientAct;
    delete exitAct;
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
    for(i=0;i<=game.boardsize;i++)
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
    for (i = 0; i < game.boardsize; i++)
    {
        for (j = 0; j < game.boardsize; j++)
        {
            if (game.getPiece (i, j) == game.player1)
                drawPiece(Qt::black, i, j);
            else if (game.getPiece (i, j) == game.player2)
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
        painter.drawEllipse(QPoint(i* spacer + 0.5*spacer + boardstart, j*spacer + spacer*0.5 + boardstart),
                            15, 15);
    }
    painter.restore();
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setStatusTip(tr("Create a new Game"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newGame()));

    setPAct = new QAction(tr("&Set Player"), this);
    setPAct->setStatusTip(tr("Set Default Player"));
    connect(setPAct, SIGNAL(triggered()), this, SLOT(setDefaultPlayer()));

    serverAct = new QAction(tr("&Wait For Connection"), this);
    serverAct->setStatusTip(tr("Work As Server"));
    connect(serverAct, SIGNAL(triggered()), this, SLOT(workAsServer()));

    clientAct = new QAction(tr("&Set Player"), this);
    clientAct->setStatusTip(tr("Work As Client"));
    connect(clientAct, SIGNAL(triggered()), this, SLOT(workAsClient()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setStatusTip(tr("Set Default Player"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(serverAct);
    fileMenu->addAction(clientAct);
    fileMenu->addAction(exitAct);
}


void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int x, y;
    if(e->x() >= boardstart && e->x() < boardend &&
       e->y() >= boardstart && e->y() < boardend && !game.isgameEnd ())
    {
        x = (e->x() - boardstart) / spacer;
        y = (e->y() - boardstart) / spacer;
        if (!game.isPiece(x, y))
        {
            game.putPiece(x, y);
            game.switchPlayer();
        }
        if(game.isWin(x, y))
        {
            game.setEndFlag ();
            update();
            //setEnabled(false);
            QMessageBox::information(this, "Win",
                                     game.getLast_player () == game.player1?"player1 Win":"player2 Win",
                                     QMessageBox::Ok);
        }
    }
    update();
}

void MainWindow::newGame()
{
    game.initBoard();
    update();
}

void MainWindow::setDefaultPlayer()
{

}

void MainWindow::workAsServer()
{
    serverDialog = new ServerDialog();
    serverDialog->show ();
}

void MainWindow::workAsClient()
{

}

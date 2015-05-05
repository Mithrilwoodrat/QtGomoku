#include "serverdialog.h"
ServerDialog::ServerDialog(QWidget *parent)
{
    InitUI ();
}

ServerDialog::~ServerDialog()
{

}

void ServerDialog::InitUI()
{
    setFixedSize (300,300);
    setWindowFlags (Qt::WindowCloseButtonHint);
    Vboxlayout = new QVBoxLayout;
    Vboxlayout->setSizeConstraint(QLayout::SetNoConstraint);
    setLayout (Vboxlayout);
    portLabel = new QLabel("port");
    message = new QLabel("Get Message");
    portEditor = new QLineEdit("6666"); //默认端口为6666
    HboxLayout = new QHBoxLayout;
    HboxLayout->addWidget (portLabel);
    HboxLayout->addWidget (portEditor);
    Vboxlayout->addLayout (HboxLayout);
    waitConnetion = new QPushButton("Start Server");
    Vboxlayout->addWidget (waitConnetion);
    Vboxlayout->addWidget (message);
    connect (waitConnetion,SIGNAL(clicked()),SLOT(start())); //点击按钮后初始化Server
}
void ServerDialog::InitServer()
{
    QString port;
    int port_int;
    port = portEditor->text();
    port_int = port.toInt();
    listenSocket = new QTcpServer;
    listenSocket->listen(QHostAddress::Any,port_int);
    QObject::connect(listenSocket,SIGNAL(newConnection()),SLOT(getConnected()));//start to listen port
}

void ServerDialog::start()
{
    InitServer ();
}

void ServerDialog::getConnected()
{
    message->setText ("get conneted");
    rwSocket = listenSocket->nextPendingConnection();
    QObject::connect(rwSocket,SIGNAL(readyRead()),SLOT(getText()));
}

void ServerDialog::getText()
{
    msg = rwSocket->readAll ().constData ();
    qDebug (msg.toAscii ().data ());
    message->setText (msg);
}




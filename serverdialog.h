#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H
#include <QDialog>
#include <QTcpSocket>
#include <QTcpServer>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class ServerDialog : public QDialog
{
  Q_OBJECT

public:
  explicit ServerDialog(QWidget *parent = 0);
  ~ServerDialog();
  void InitServer();
public slots:
  void start();
  void getConnected();
  void getText();
private:
  void InitUI();
  QTcpServer *listenSocket;
  QTcpSocket *rwSocket;
  QVBoxLayout *Vboxlayout;
  QHBoxLayout *HboxLayout;
  QLabel *portLabel;
  QLineEdit *portEditor;
  QLabel *message;
  QPushButton *waitConnetion;
  QString msg;
};

#endif // SERVERDIALOG_H

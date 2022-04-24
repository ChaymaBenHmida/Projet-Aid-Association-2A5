#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include<QTcpServer>
#include<QTcpSocket>


namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
private slots:

    void conexion_nueva();
    void leer_socket();
    void on_sendButton_clicked();

private:
    Ui::chat *ui;

    QTcpSocket *mSocket;
    QTcpServer *mServer;
};

#endif // CHAT_H

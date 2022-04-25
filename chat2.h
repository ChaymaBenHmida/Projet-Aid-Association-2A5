#ifndef CHAT2_H
#define CHAT2_H

#include <QDialog>
#include<QTcpSocket>

namespace Ui {
class chat2;
}

class chat2 : public QDialog
{
    Q_OBJECT

public:
    explicit chat2(QWidget *parent = nullptr);
    ~chat2();

private slots:
    void leer();
    void on_pushButton_clicked();

private:
    Ui::chat2 *ui;
       QTcpSocket *mSocket;
};

#endif // CHAT2_H

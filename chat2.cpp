#include "chat2.h"
#include "ui_chat2.h"

chat2::chat2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat2)
{
    ui->setupUi(this);
    mSocket=new QTcpSocket(this);
   mSocket->connectToHost("localhost",2000);
   connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));
}

chat2::~chat2()
{
    delete ui;
}
void chat2::leer()
{
    QByteArray buffer;
    buffer.resize(mSocket->bytesAvailable());
    mSocket->read(buffer.data(),buffer.size());
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->appendPlainText(QString(buffer));
}


void chat2::on_pushButton_clicked()
{
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());
    ui->plainTextEdit->appendPlainText(ui->lineEdit->text());
    ui->lineEdit->clear();
}



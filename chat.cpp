#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
   ui->setupUi(this);
    mServer=new QTcpServer(this);
    mServer->listen(QHostAddress::Any,2000);
    mSocket=new QTcpSocket(this);
    connect(mServer,SIGNAL(newConnection()),this,SLOT(conexion_nueva()));
}

chat::~chat()
{
    delete ui;
}
void chat::conexion_nueva()
{
    mSocket=mServer->nextPendingConnection();
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer_socket()));
}

void chat::leer_socket()
{
    QByteArray buffer;
    buffer.resize(mSocket->bytesAvailable());
    mSocket->read(buffer.data(),buffer.size());
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->appendPlainText(QString(buffer));
}


void chat::on_sendButton_clicked()
{
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());
    ui->plainTextEdit->appendPlainText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

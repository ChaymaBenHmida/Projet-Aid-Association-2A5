#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include<QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{
    QString log = ui->id->text();
     QString mdp = ui->pwd->text();
     if (log=="employe" && mdp=="chahrazed")
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("welcome chahrazed (gestion employe)\n"
                                 "Click OK to enter."), QMessageBox::Ok);

         M =new MainWindow(this);
         M->show();

     }

         else if (log=="handicape" && mdp=="maryem")
         {
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("welcome maryem (gestion handicape)\n"
                                     "Click OK to enter."), QMessageBox::Ok);


             M =new MainWindow(this);
             M->show();
         }



else {
QMessageBox::critical(nullptr, QObject::tr("database is open"),
            QObject::tr("wrong admin or password.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
     }
}








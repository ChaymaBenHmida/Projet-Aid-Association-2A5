#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QSqlTableModel>
#include "connection.h"
#include "login.h"

#include<QTranslator>
#include <QInputDialog>
#include"chat.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  /*  MainWindow w;
    Connection c;
    bool test=c.createconnection();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
*/
    //TRADUCTION
            QTranslator t;
            QStringList languages;
            languages <<"arabic"<<"French";
            QString lang=QInputDialog::getItem(NULL,"select language","language",languages);
            if(lang=="arabic"){
                t.load(":/arabic.qm");

            }
            if(lang!="French")
            {
                a.installTranslator(&t);
            }


    login L;
    Connection cL;
    bool testL=cL.createconnect();
    if(testL)
    {L.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                    QObject::tr("Connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                    QObject::tr("Connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();





}


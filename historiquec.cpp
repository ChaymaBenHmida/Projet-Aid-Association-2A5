#include "historiquec.h"

#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QTableView>
#include<iostream>
#include <QString>


historiquec::historiquec()
{
mFilename="Historique.txt";
}

QString historiquec::read()
{
QFile mFile(mFilename);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"Il ne peut pas!";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}

void historiquec::write(QString text)
{
    QString aux=read();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
QFile mFile(mFilename);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"Il ne peut pas!";
}
QTextStream out (&mFile);


aux+=text;
out << aux << "\n";
mFile.flush();
mFile.close();

}


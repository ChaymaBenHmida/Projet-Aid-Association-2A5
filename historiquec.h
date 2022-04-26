#ifndef HISTORIQUEC_H
#define HISTORIQUEC_H


#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDateTime>

class historiquec
{
public:
    historiquec();
    void write(QString);
    QString read();
    //void save(QString,QString);
    //QString load();
private:
    QString mFilename; //tmp;


};

#endif // HISTORIQUEC_H

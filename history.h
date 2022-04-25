#ifndef HISTORY_H
#define HISTORY_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QDate>

class History
{
    QString tmp;
  public:
      History();
      void save(QString,QString,QString,QString);
      QString load();

};
#endif // HISTORY_H

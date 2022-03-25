#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{ QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeconnect();
};


#endif // CONNECTION_H

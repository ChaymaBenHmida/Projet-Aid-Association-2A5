#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("source_projet2A");
db.setUserName("tasnim");//inserer nom de l'utilisateur
db.setPassword("tasnim");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connection::closeconnect(){db.close();}

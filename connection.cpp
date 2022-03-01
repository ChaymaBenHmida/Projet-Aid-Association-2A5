#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
  db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("Source_projet2A");
db.setUserName("chahrazed");//inserer nom de l'utilisateur
db.setPassword("chahrazed");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void Connection::closeconnect(){db.close();}

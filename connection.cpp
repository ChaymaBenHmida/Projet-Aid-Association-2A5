#include "connection.h"

//test atelier git
//testGestionActivite
Connection::Connection()
{

}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("chayma");//inserer nom de l'utilisateur
db.setPassword("esprit22");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void Connection::closeconnection(){
    db.close();
}

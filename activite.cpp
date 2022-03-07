#include "activite.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QTableView>

Activite::Activite(int idA,QString nomA,QString dateA)
{
   this->idA=idA;
   this->nomA=nomA;
   this->dateA=dateA;
}

int Activite::getidA(){
   return idA;

}
QString Activite::getnomA(){
  return nomA;

}

QString Activite::getdateA(){
  return dateA;
}

void Activite::setidA(int idA){
    this->idA=idA;
}
void Activite::setnomA(QString nomA){
    this->nomA=nomA;
}

void Activite::setdateA(QString dateA){
    this->dateA=dateA;
}


bool Activite::ajouter(){
  QSqlQuery query;
  QString id_string= QString::number(idA);
       query.prepare("INSERT INTO ACTIVITE (idA,nomA,dateA)"
                     "VALUES (:idA,:nomA,:dateA)");
       query.bindValue(":idA",id_string);
       query.bindValue(":nomA",nomA);
       query.bindValue(":dateA",dateA);
   return query.exec();
}

bool Activite::supprimer(int idA)
{
    QSqlQuery query;
    query.prepare("DELETE from ACTIVITE where idA= :idA");
     query.bindValue(0,idA);
       return query.exec();
}

QSqlQueryModel* Activite::afficher(){

 QSqlQueryModel* model =new QSqlQueryModel();
 model->setQuery("SELECT* FROM ACTIVITE");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id de l'activité"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom de l'activité"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date de l'activité"));
 return model;
}
bool Activite::modifier()
{
   QSqlQuery query;
   QString id_string= QString::number(idA);

   query.prepare("update ACTIVITE set idA=:idA,nomA=:nomA,dateA=:dateA where idA=:idA");
   query.bindValue(":idA",id_string);
   query.bindValue(":nomA",nomA);
   query.bindValue(":dateA",dateA);
return query.exec();

}

QSqlQueryModel * Activite::recherche(QString nomA)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ACTIVITE WHERE nomA LIKE '%"+nomA+"%'" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
return model ;
}

#include "activite.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QTableView>
#include<iostream>
#include "notification.h"


using namespace std;

Activite::Activite(int idA,QString nomA,QString dateA,QString description,int statu)
{
   this->idA=idA;
   this->nomA=nomA;
   this->dateA=dateA;
   this->description=description;
   this->statu=statu;
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

QString Activite::getdescription(){
    return description;
}

int Activite::getstatu(){
    return statu;
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

void Activite::setdescription(QString description){
     this->description=description;
}

void Activite::setstatu(int statu){
    this->statu=statu;
}


bool Activite::ajouter(){
  QSqlQuery query;
  QString id_string= QString::number(idA);
  QString stati_string= QString::number(statu);
       query.prepare("INSERT INTO ACTIVITE (idA,nomA,dateA,description,statu)"
                     "VALUES (:idA,:nomA,:dateA,:description,:statu)");
       query.bindValue(":idA",id_string);
       query.bindValue(":nomA",nomA);
       query.bindValue(":dateA",dateA);
        query.bindValue(":description",description);
         query.bindValue(":statu",stati_string);
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

 model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("CinEmploye"));
 return model;

}

bool Activite::modifier()
{
   QSqlQuery query;
   QString id_string= QString::number(idA);
   QString stati_string= QString::number(statu);
   query.prepare("update ACTIVITE set idA=:idA,nomA=:nomA,dateA=:dateA,description=:description,statu=:statu where idA=:idA");
   query.bindValue(":idA",id_string);
   query.bindValue(":nomA",nomA);
   query.bindValue(":dateA",dateA);
   query.bindValue(":description",description);
   query.bindValue(":statu",stati_string);

  return query.exec();

}
//LES METIERS
//RECHERCHE PAR NOM
QSqlQueryModel * Activite::recherche(QString nomA)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ACTIVITE WHERE nomA LIKE '%"+nomA+"%'" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));
return model ;
}

//FILTRAGE SELON STATU+NOTIFICATION
QSqlQueryModel * Activite::StatuEncours()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
      cout <<"L'activite est en cours"<<endl;

     model->setQuery("SELECT * FROM ACTIVITE where (statu=0)" );
       model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

      return model ;

      }

  QSqlQueryModel * Activite::StatuTodo()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
      cout <<"L'activite est a venir "<<endl;

    model->setQuery("SELECT * FROM ACTIVITE where (statu=1)" );
      model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
      model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

      return model ;

      }


  QSqlQueryModel * Activite::StatuDone()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
      cout <<"L'activite est passee"<<endl;

    model->setQuery("SELECT * FROM Activite where (statu=2)" );
      model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
      model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));


QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
notifyIcon->setIcon(QIcon("notification.png"));
//notifyIcon->setVisible(1);
notifyIcon->show();
notifyIcon->showMessage("Notification","Attention !! Activité(s) Passée(s)!",QSystemTrayIcon::Information,15000);
      return model ;

      }
//TRI PAR NOM
  QSqlQueryModel * Activite::TriParNomC()
{
   QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM ACTIVITE order by nomA ASC");
    q->exec();
    model->setQuery(*q);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

    return model;
}

  QSqlQueryModel * Activite::TriParNomD()
{
   QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM ACTIVITE order by nomA DESC");
    q->exec();
    model->setQuery(*q);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

    return model;
}
//TRI PAR ID
    QSqlQueryModel * Activite::TriParIdC()
  {
     QSqlQuery * q = new  QSqlQuery ();
     QSqlQueryModel * model = new  QSqlQueryModel ();
      q->prepare("SELECT * FROM ACTIVITE order by idA ASC");
      q->exec();
      model->setQuery(*q);
      model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
      model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

      return model;
  }

    QSqlQueryModel * Activite::TriParIdD()
  {
     QSqlQuery * q = new  QSqlQuery ();
     QSqlQueryModel * model = new  QSqlQueryModel ();
      q->prepare("SELECT * FROM ACTIVITE order by idA DESC");
      q->exec();
      model->setQuery(*q);
      model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
      model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

      return model;
  }
//TRI PAR DATE
   QSqlQueryModel * Activite::TriParDateC()
  {
     QSqlQuery * q = new  QSqlQuery ();
     QSqlQueryModel * model = new  QSqlQueryModel ();
      q->prepare("SELECT * FROM ACTIVITE order by dateA ASC");
      q->exec();
      model->setQuery(*q);
      model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
      model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

      return model;
  }

    QSqlQueryModel * Activite:: TriParDateD()
  {
     QSqlQuery * q = new  QSqlQuery ();
     QSqlQueryModel * model = new  QSqlQueryModel ();
      q->prepare("SELECT * FROM ACTIVITE order by dateA DESC");
      q->exec();
      model->setQuery(*q);
      model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
      model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
      model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));

      return model;
  }
//IMPRESSION
 QSqlQuery Activite::editview(QString)
{
        QSqlQuery query;
         //query.prepare("select * from handicape where id='"+info+"'");
         query.prepare("SELECT * FROM ACTIVITE ");
         if(query.exec())
          {
         return query;
          }

}
//RECHERCHE PAR STATU
 QSqlQueryModel * Activite::rechercheS(QString statu)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM ACTIVITE WHERE statu LIKE '%"+statu+"%'" );

 model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));
 return model ;
 }
 //RECHERCHE PAR ID
  QSqlQueryModel * Activite::rechercheI(QString idA)
  {
  QSqlQueryModel * model= new QSqlQueryModel();
  model->setQuery("SELECT * FROM ACTIVITE WHERE idA LIKE '%"+idA+"%'" );

  model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
  model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal,QObject::tr("Date"));
  model->setHeaderData(3, Qt::Horizontal,QObject::tr("Description"));
  model->setHeaderData(4, Qt::Horizontal,QObject::tr("Statu"));
  return model ;
  }

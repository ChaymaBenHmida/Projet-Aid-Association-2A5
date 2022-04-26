#include "dons.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Dons::Dons()
{

id=0;
nom="";
prenom="";
role="";
produit="";
montant=0;
dateD=QDate::currentDate();
}

Dons::Dons(int id,QString nom,QString prenom,QString role ,QString produit ,int montant ,QDate dateD)
{
     this->nom=nom; this->prenom=prenom; this->role=role; this->produit=produit; this->id=id; this->montant=montant; this->dateD=dateD;

}

QString Dons::getnom(){return nom;}
QString Dons::getprenom(){return prenom;}
QString Dons::getrole(){return role;}
QString Dons::getproduit(){return produit;}
int Dons::getmontant(){return montant;}
int Dons::getid(){return id;}
QDate Dons::getdateD(){return dateD;}



void Dons::setnom(QString nom){this->nom=nom;}
void Dons::setprenom(QString prenom){this->prenom=prenom;}
void Dons::setrole(QString role){this->role=role;}
void Dons::setproduit(QString produit ){this->produit=produit; }
void Dons::setmontant(int montant){this->montant=montant;}
void Dons::setid(int id ){this->id=id;}
void Dons::setdateD(QDate dateD){this->dateD=dateD;}

bool Dons::ajouter()
{


    QSqlQuery query;
    QString res=QString::number(id);
          query.prepare("INSERT INTO dons ( id,prenom,nom,role,produit,montant,dateD) "
                        "VALUES ( :id,:prenom,:nom,:role,:produit,:montant,:dateD)");
          query.bindValue(":id", res);
          query.bindValue(":prenom", prenom);
          query.bindValue(":nom", nom);
          query.bindValue(":role", role);
          query.bindValue(":produit", produit);
          query.bindValue(":montant", montant);
          query.bindValue(":dateD", dateD);
          return   query.exec();




}
bool Dons::supprimer(int id)
{
    QSqlQuery query;

          query.prepare("DELETE from dons where id =:id");

          query.bindValue(":id", id);

          return   query.exec();
}

QSqlQueryModel* Dons::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();



         model->setQuery("SELECT id,prenom,nom,role,produit,montant ,dateD FROM dons");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Prénom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Montant"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));



    return model;
}
bool Dons::modifier(int id)
{
    QSqlQuery query;

   query.prepare("UPDATE dons SET  prenom=:prenom, nom=:nom ,role=:role ,produit=:produit, montant=:montant ,dateD=:dateD WHERE id=:id");

    query.bindValue(":id",id);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":role",role);
    query.bindValue(":produit",produit);
    query.bindValue(":montant",montant);
    query.bindValue(":dateD",dateD);


    return query.exec();
}




QSqlQueryModel* Dons::recherche_nom(QString nom)
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT id,prenom,nom,role,produit,montant,dateD FROM dons WHERE  nom LIKE '%"+nom+"%'");

 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Montant"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));


query.exec();
  return  model;
}

QSqlQueryModel* Dons::recherche_prenom(QString prenom)
  {
    QSqlQueryModel* model=new QSqlQueryModel();
  QSqlQuery query;

   model->setQuery("SELECT id,prenom,nom,role,produit,montant,dateD FROM dons WHERE  nom LIKE '%"+prenom+"%'");

   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Montant"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));


  query.exec();
    return  model;

}

QSqlQueryModel* Dons::recherche_role(QString role)
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT id,prenom,nom,role,produit,montant,dateD FROM dons WHERE role LIKE '%"+role+"%' ");

 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Montant"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date"));


query.exec();
  return  model;




}
/*QSqlQueryModel* Dons::recherche_role2()
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT * FROM dons WHERE  Role LIKE 'e%'");

 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("¨Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Montant"));


query.exec();
  return  model;




}
QSqlQueryModel* Dons::recherche_role3()
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT * FROM dons WHERE  Role LIKE 'b%' ");

 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("¨Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Role"));
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Montant"));


query.exec();
  return  model;




}
*/


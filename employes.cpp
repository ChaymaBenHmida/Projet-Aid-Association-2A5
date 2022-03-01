#include "employes.h"
#include <QSqlQuery>
#include <QtDebug>
Employe::Employe()
{
    id=0;cin=0,telephone=0,jours_de_travail=0;
    nom= " ";prenom="",fonction="";
    salaire=0;
}
Employe::Employe(int id,int cin,int telephone,int jours_de_travail,QString nom,QString prenom,QString fonction,int salaire)
 {this->id=id;this->cin=cin;this->telephone=telephone;this->jours_de_travail=jours_de_travail;this->nom=nom;this->prenom=prenom;this->fonction=fonction;this->salaire=salaire;

}
int Employe::getid(){return id;}
int Employe:: getcin(){return cin;}
int Employe:: gettelephone(){return telephone;}
int Employe:: getjours_de_travail(){return jours_de_travail;}
QString Employe:: getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
QString Employe:: getfonction(){return fonction;}
int Employe::getsalaire(){return salaire;}
void Employe::setid(int id){this->id=id;}
void Employe::setcin(int cin){this->cin=cin;}
void Employe::settelephone(int telephone){this->telephone=telephone;}
void Employe::setjours_de_travail(int jours_de_travail){this->jours_de_travail=jours_de_travail;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setfonction(QString fonction){this->fonction=fonction;}
void Employe::setsalaire(int salaire){this->salaire=salaire;}

bool Employe::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO Source_projet2A (id, cin, nom, prenom ,telephone ,jours_de_travail ,salaire ,fonction) "
                  "VALUES (:id, :cin, :nom, :prenom, :telephone, :jours_de_travail, :salaire ,:fonction)");
    query.bindValue(":id", id_string);
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
      query.bindValue(":telephone", telephone);
       query.bindValue(":jours_de_travail", jours_de_travail);
        query.bindValue(":salaire", salaire);
         query.bindValue(":fonction", fonction);
   return query.exec();


}

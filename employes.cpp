#include "employes.h"
#include <QObject>
#include <QSqlQuery>
#include <QtDebug>
Employe::Employe()
{
    cin=0;telephone=0,jours_de_travail="";
    nom= " ";prenom="",fonction="";
    salaire=0;
}
Employe:: Employe(int cin,QString nom, QString prenom,int telephone,QString jours_de_travail,int salaire,QString fonction)
 {
this->cin=cin;
this->telephone=telephone;
this->jours_de_travail=jours_de_travail;
this->nom=nom;
this->prenom=prenom;
this->fonction=fonction;
this->salaire=salaire;

}
int Employe::getcin(){return cin;}

int Employe:: gettelephone(){return telephone;}
QString Employe:: getjours_de_travail(){return jours_de_travail;}
QString Employe:: getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
QString Employe:: getfonction(){return fonction;}
int Employe::getsalaire(){return salaire;}
void Employe::setcin(int cin){this->cin=cin;}

void Employe::settelephone(int telephone){this->telephone=telephone;}
void Employe::setjours_de_travail(QString jours_de_travail){this->jours_de_travail=jours_de_travail;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setfonction(QString fonction){this->fonction=fonction;}
void Employe::setsalaire(int salaire){this->salaire=salaire;}

bool Employe::ajouter()
{


    QSqlQuery query;
    QString cin_string = QString::number(cin);
    query.prepare("INSERT INTO employe(cin,nom, prenom ,telephone ,jours_de_travail ,salaire ,fonction) "
                  "VALUES(:cin, :nom, :prenom, :telephone, :jours_de_travail, :salaire ,:fonction)");
    query.bindValue(":cin", cin_string);

    query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
      query.bindValue(":telephone", telephone);
       query.bindValue(":jours_de_travail", jours_de_travail);
        query.bindValue(":salaire", salaire);
         query.bindValue(":fonction", fonction);
   return query.exec();


}
QSqlQueryModel * Employe::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));

    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("jrs"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("sal"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("fn"));



    return  model;
}
bool Employe::modifier(int cin)
{
    QSqlQuery query;

   query.prepare("UPDATE Employe SET  nom=:nom ,prenom=:prenom,telephone=:telephone, jours_de_travail=:jours_de_travail,salaire=:salaire ,fonction=:fonction WHERE cin=:cin");

    query.bindValue(":cin",cin);
    query.bindValue(":telephone",telephone);
    query.bindValue(":nom",nom);

    query.bindValue(":prenom",prenom);
    query.bindValue(":jours_de_travail",jours_de_travail);
     query.bindValue(":fonction",fonction);
      query.bindValue(":salaire",salaire);


    return query.exec();
}
bool Employe::supprimer(int cin)
{
QSqlQuery query;
QString res = QString::number(cin);
query.prepare("Delete from employe where cin= :cin");
query.bindValue(":cin",cin);
return query.exec();
}

QSqlQuery Employe::editview(QString info)

{
QSqlQuery query;
//query.prepare("select * from employe where id='"+info+"'");
query.prepare("select * from employe ");

if(query.exec())
 {
return query;
 }

}
//---------------triii------
QSqlQueryModel * Employe::afficher_tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYE order by NOM asc ");

    return model;
}
QSqlQueryModel * Employe::afficher_tri_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYE order by PRENOM asc ");

    return model;
}
QSqlQueryModel * Employe::afficher_tri_fonction()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYE order by FONCTION asc ");

    return model;
}

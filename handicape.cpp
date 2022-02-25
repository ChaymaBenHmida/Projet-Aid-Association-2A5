#include "handicape.h"
#include<QObject>
#include<QSqlQuery>
#include <QtDebug>

handicape::handicape()
{
    id=0;
    nom="";
    prenom="";
    age=0;
    tel=0;
}


handicape::handicape(int i,QString n,QString p,int a,int t)
{
    this->id=i;
    this->nom=n;
    this->prenom=p;
    this->tel=t;
    this->age=a;

}


bool handicape::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO  handicape(id,nom,prenom,age,tel)""values(:id, :nom, :prenom, :age, :tel)");

    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":tel",tel);

    return query.exec();
}



bool handicape::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id);

   query.prepare("UPDATE handicape set nom='"+nom+"',prenom='"+prenom+"',age='"+age+"',tel='"+tel+"' where id='"+id+"'");


    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    query.bindValue(":age",age);
    query.bindValue(":tel",tel);


    return query.exec();
}


bool handicape::supprimer(int id)
{
     QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Delete from handicape where id= :id");
    query.bindValue(":id",res);

    return query.exec();
}


QSqlQueryModel * handicape::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from handicape ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("tel"));

    return  model;
}

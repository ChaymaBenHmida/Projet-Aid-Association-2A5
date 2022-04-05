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
    img="";
}


handicape::handicape(int i,QString n,QString p,int a,int t,QString m)
{
    this->id=i;
    this->nom=n;
    this->prenom=p;
    this->tel=t;
    this->age=a;
    this->img=m;
}


bool handicape::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("INSERT INTO  handicape(id,nom,prenom,age,tel,img)""values(:id, :nom, :prenom, :age, :tel, :img)");

    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":tel",tel);
    query.bindValue(":img",img);
    return query.exec();
}



bool handicape::modifier(int id)
{
    QSqlQuery query;

   query.prepare("UPDATE handicape SET nom=:nom ,prenom=:prenom, age=:age, tel=:tel, img=:img WHERE id=:id");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    query.bindValue(":age",age);
    query.bindValue(":tel",tel);
    query.bindValue(":img",img);



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


QSqlQuery handicape::editview(QString info)

{
QSqlQuery query;
//query.prepare("select * from handicape where id='"+info+"'");
query.prepare("select * from handiecap ");

if(query.exec())
 {
return query;
 }

}

QSqlQuery handicape::editview_rdv(QString info)

{
QSqlQuery query;

query.prepare("select * from test ");

if(query.exec())
 {
return query;
 }

}


QSqlQueryModel * handicape::afficher_rdv()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from test  ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("rdvv"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));

    return model ;
};

QSqlQueryModel * handicape::afficher_id()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select id from handicape");
return model ;
};

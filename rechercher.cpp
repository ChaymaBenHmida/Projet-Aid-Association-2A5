#include "handicape.h"
#include<QObject>
#include<QSqlQuery>
#include <QtDebug>



QSqlQueryModel * handicape::recherche_age(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        if(nom=="")
        {

        }
        else {
        model->setQuery("SELECT * FROM handicape WHERE (age='"+nom+"') ;");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("tel"));
      }
    return model ;
}

QSqlQueryModel * handicape::recherche_nom(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        if(nom!="")
        {
            model->setQuery("SELECT * FROM handicape WHERE (nom=  '"+nom+"') ;");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("tel"));
        }


    return model ;
}

QSqlQueryModel * handicape::recherche_prenom(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        if(nom!="")
        {
            model->setQuery("SELECT * FROM handicape WHERE (prenom = '"+nom+"') ;");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("tel"));
        }


    return model ;
}



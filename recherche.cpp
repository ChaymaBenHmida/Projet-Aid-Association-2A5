#include "employes.h"
#include<QObject>
#include<QSqlQuery>
#include <QtDebug>



QSqlQueryModel * Employe::recherche_fonction(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        if(nom=="")
        {

        }
        else {
        model->setQuery("SELECT * FROM employe WHERE (fonction='"+nom+"') ;");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("jrs"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("sal"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("fn"));
      }
    return model ;
}

QSqlQueryModel * Employe::recherche_nom(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        if(nom!="")
        {
            model->setQuery("SELECT * FROM employe WHERE (nom=  '"+nom+"') ;");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("jrs"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("sal"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("fn"));
        }


    return model ;
}

QSqlQueryModel * Employe::recherche_prenom(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
        if(nom!="")
        {
            model->setQuery("SELECT * FROM employe WHERE (nom=  '"+nom+"') ;");


            model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("jrs"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("sal"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("fn"));
        }


    return model ;
}

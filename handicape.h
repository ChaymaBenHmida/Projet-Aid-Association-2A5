#ifndef HANDICAPE_H
#define HANDICAPE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QFileDialog>

class handicape
{ QString nom , prenom, img ;
    int id , age , tel ;

public:
    //constructeurs
    handicape();
    handicape(int,QString,QString,int,int,QString);

    //getters
    QString getnom(){return  nom;}
    QString getprenom(){return prenom;}
    QString getimg(){return  img;}
    int getid(){return id;}
    int getage(){return age;}
    int gettel(){return tel;}

    //setters
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setimg(QString m){img=m;}
    void setid(int i){id=i;}
    void settel(int t){tel=t;}
    void setage(int a){age=a;}

    //Method
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);

    //rechercher
   QSqlQueryModel *  recherche_age(QString );
   QSqlQueryModel * recherche_nom(QString );
   QSqlQueryModel * recherche_prenom(QString );

   //print
   QSqlQuery editview(QString);

   //notification

   void notifications_supprimer();
   void notifications_ajouter();
   void notifications_modifier();

QSqlQuery editview_rdv(QString info);
   QSqlQueryModel * afficher_rdv();
   QSqlQueryModel * afficher_id();
};

#endif // HANDICAPE_H

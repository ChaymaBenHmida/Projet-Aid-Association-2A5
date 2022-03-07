#ifndef HANDICAPE_H
#define HANDICAPE_H
#include<QSqlQuery>
#include<QSqlQueryModel>


class handicape
{ QString nom , prenom ;
    int id , age , tel ;

public:
    //constructeurs
    handicape();
    handicape(int,QString,QString,int,int);

    //getters
    QString getnom(){return  nom;}
    QString getprenom(){return prenom;}
    int getid(){return id;}
    int getage(){return age;}
    int gettel(){return tel;}

    //setters
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setid(int i){id=i;}
    void settel(int t){tel=t;}
    void setage(int a){age=a;}

    //Method
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);

    //rechercher
   QSqlQueryModel *  recherche_age(QString nom);
   QSqlQueryModel * recherche_nom(QString nom);
   QSqlQueryModel * recherche_prenom(QString nom);

};

#endif // HANDICAPE_H

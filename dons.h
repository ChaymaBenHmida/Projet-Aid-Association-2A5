#ifndef DONS_H
#define DONS_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class Dons
{

public:
    Dons();
    Dons(int,QString,QString,QString,QString,int,QDate);

    int getid();
    QString getnom();
    QString getprenom();
    QString getrole();
    QString getproduit();
    int getmontant();
    QDate getdate();


     void setnom(QString );
      void setprenom(QString );
      void setrole(QString);
      void setproduit(QString );
      void setmontant(int);
      void setid(int);
      void setdate(QDate);


bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);

bool modifier(int);
QSqlQueryModel* recherche_nom(QString);

QSqlQueryModel* recherche_prenom(QString);
QSqlQueryModel* recherche_role(QString);

private:
int id;
QString nom,prenom,role,produit;
int montant;
QDate dates;


};

#endif // DONS_H

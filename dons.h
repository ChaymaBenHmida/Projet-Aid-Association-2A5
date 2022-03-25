#ifndef DONS_H
#define DONS_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Dons
{

public:
    Dons();
    Dons(int,QString,QString,QString,QString,int);

    int getid();
    QString getnom();
    QString getprenom();
    QString getrole();
    QString getproduit();
    int getmontant();


     void setnom(QString );
      void setprenom(QString );
      void setrole(QString);
      void setproduit(QString );
      void setmontant(int);
      void setid(int);


bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
 QSqlQueryModel* recherche_id(int);
bool modifier(int);
QSqlQueryModel* recherche_nom(QString);
QSqlQueryModel* recherche_role3();
QSqlQueryModel* recherche_role2();
QSqlQueryModel* recherche_role(QString);

private:
int id;
QString nom,prenom,role,produit;
int montant;


};

#endif // DONS_H

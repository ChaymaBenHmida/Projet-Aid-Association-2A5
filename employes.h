#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
//
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int,QString,int,QString);
int getcin();

int gettelephone();
QString getjours_de_travail();
QString getnom();
QString getprenom();
QString getfonction();
int getsalaire();

void setcin(int);

void settelephone(int);
void setjours_de_travail(QString);
void setnom(QString);
void setprenom(QString);
void setfonction(QString);
void setsalaire(int);
bool ajouter();
 bool modifier(int);
 bool supprimer(int);
QSqlQueryModel * afficher();
QSqlQuery editview(QString);
QSqlQueryModel * afficher_tri_nom();
QSqlQueryModel * afficher_tri_prenom();
QSqlQueryModel * afficher_tri_fonction();
 QSqlQueryModel * recherche_nom(QString );
 QSqlQueryModel * recherche_prenom(QString );
 QSqlQueryModel * recherche_fonction(QString );
private:
    int cin,telephone,salaire;
    QString nom,prenom,fonction,jours_de_travail ;

};

#endif // EMPLOYES_H

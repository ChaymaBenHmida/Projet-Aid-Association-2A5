#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int,int,int,QString);
int getcin();

int gettelephone();
int getjours_de_travail();
QString getnom();
QString getprenom();
QString getfonction();
int getsalaire();

void setcin(int);

void settelephone(int);
void setjours_de_travail(int);
void setnom(QString);
void setprenom(QString);
void setfonction(QString);
void setsalaire(int);
bool ajouter();
 bool modifier(int);
 bool supprimer(int);
QSqlQueryModel * afficher();
private:
    int cin,telephone,jours_de_travail,salaire;
    QString nom,prenom,fonction ;

};

#endif // EMPLOYES_H

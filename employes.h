#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
class Employe
{
public:
    Employe();

    Employe(int,int,int,int,QString,QString,QString,int);
int getid();
int getcin();
int gettelephone();
int getjours_de_travail();
QString getnom();
QString getprenom();
QString getfonction();
int getsalaire();

void setid(int);
void setcin(int);
void settelephone(int);
void setjours_de_travail(int);
void setnom(QString);
void setprenom(QString);
void setfonction(QString);
void setsalaire(int);
bool ajouter();

private:
    int id,cin,telephone,jours_de_travail,salaire;
    QString nom,prenom,fonction ;

};

#endif // EMPLOYES_H

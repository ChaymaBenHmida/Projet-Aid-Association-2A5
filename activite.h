#ifndef ACTIVITE_H
#define ACTIVITE_H
#include<QSqlQueryModel>
#include<QString>

class Activite
{
public:
//constructeurs
    Activite(){} //constructeur par defaut
    ~Activite(){} //destructeur
    Activite(int,QString,QString);//constructeur parametré
//getters
        int getidA();
        QString getnomA();
        QString getdateA();
//setters
    void setidA(int);
    void setnomA(QString);
    void setdateA(QString);

//les methodes
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* recherche(QString);

private:
    int  idA;
    QString nomA,dateA ;
};

#endif // ACTIVITE_H



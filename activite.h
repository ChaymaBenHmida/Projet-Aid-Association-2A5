#ifndef ACTIVITE_H
#define ACTIVITE_H
#include<QSqlQueryModel>
#include<QString>
#include <QDate>
//commit
class Activite
{
public:
//constructeurs
    Activite(){} //constructeur par defaut
    ~Activite(){} //destructeur
    Activite(int,QString,QString,QString,int);//constructeur parametré
//getters
        int getidA();
        QString getnomA();
        QString getdateA();
        QString getdescription();
        int getstatu();
//setters
    void setidA(int);
    void setnomA(QString);
    void setdateA(QString);
    void setdescription(QString);
    void setstatu(int);

//les methodes
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel * StatuEncours();
    QSqlQueryModel * StatuDone();
    QSqlQueryModel * StatuTodo();
    QSqlQueryModel * TriParNomC();
    QSqlQueryModel * TriParNomD();
    QSqlQueryModel * TriParIdC();
    QSqlQueryModel * TriParIdD();
    QSqlQueryModel * TriParDateC();
    QSqlQueryModel * TriParDateD();
   //IMPRESSION
    QSqlQuery editview(QString);
  QSqlQueryModel* rechercheS(QString);
  QSqlQueryModel* rechercheI(QString);

private:
    int  idA,statu;
    QString nomA,dateA,description;    

};

#endif // ACTIVITE_H



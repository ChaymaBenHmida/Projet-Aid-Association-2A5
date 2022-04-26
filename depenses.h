#ifndef DEPENSES_H
#define DEPENSES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QDebug>
#include <QDate>


class depenses
{
public:
    depenses();
    depenses(int,QDate,QString,int);
    void setid_depenses(int n);
    void setdate_depenses(QDate n);
    void settype_depenses(QString n);
    void setmontant(int n);

    int getid_depenses();
    QDate getdate_depenses();
    QString gettype_depenses();
    int getmontant();

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel*  afficher();
    bool modifier(int,QDate,QString,int);
    void creerpdf();

private:
    QString  type_depenses;
    QDate date_depenses;
    int id_depenses,montant;
};

#endif // DEPENSES_H

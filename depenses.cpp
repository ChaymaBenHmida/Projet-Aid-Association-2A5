#include "depenses.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include "QDebug"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>

#include <QSqlQueryModel>
#include <QDate>

using namespace std;

depenses::depenses()
{
id_depenses=0;
date_depenses=QDate::currentDate();
type_depenses="";
montant=0;

}
depenses::depenses (int id_depenses ,QDate date_depenses ,QString type_depenses ,int montant)
{this->id_depenses=id_depenses; this->date_depenses=date_depenses;this->type_depenses=type_depenses;this->montant=montant;}

int depenses::getid_depenses(){return id_depenses ;}
QDate depenses::getdate_depenses(){return date_depenses;}
QString depenses::gettype_depenses()  { return type_depenses;}
int depenses::getmontant(){return montant;}

void depenses::setid_depenses(int id_depenses){this->id_depenses=id_depenses;}
void depenses::setdate_depenses(QDate date_depenses){this->date_depenses=date_depenses;}
void depenses::settype_depenses(QString type_depenses){this->type_depenses=type_depenses;}
void depenses::setmontant(int montant){this->montant=montant;}


bool depenses::ajouter()
{

    QSqlQuery query;
    QString jj= QString::number(id_depenses);
    QString kk= QString::number(montant);
        query.prepare("insert into DEPENSES (id_depenses,date_depenses,type_depenses,montant )"
                "values(:id_depenses,:date_depenses,:type_depenses,:montant )");
        query.bindValue(":id_depenses",jj);
        query.bindValue(":date_depenses", date_depenses);
        query.bindValue(":montant", kk);
        query.bindValue(":type_depenses", type_depenses);

        return    query.exec();


}

bool depenses::supprimer(int id_depenses)
{
    QSqlQuery query;




    query.prepare("Delete from DEPENSES where id_depenses= :id_depenses");
    query.bindValue(":id_depenses",id_depenses);

    return query.exec();
}

QSqlQueryModel* depenses::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;

          model->setQuery("SELECT* FROM DEPENSES");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Montant"));

          return model;
}




bool depenses::modifier(int id_depenses, QDate date_depenses, QString type_depenses ,int montant)
{
    QSqlQuery query;
    QString jj= QString::number(id_depenses);
    QString kk= QString::number(montant);
        query.prepare("update DEPENSES set date_depenses=:date_depenses,type_depenses=:type_depenses,montant=:montant where id_depenses=:id_depenses");
        query.bindValue(":id_depenses",jj);
        query.bindValue(":date_depenses", date_depenses);
        query.bindValue(":montant", kk);
        query.bindValue(":type_depenses", type_depenses);

        return    query.exec();

}

void depenses::creerpdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM depenses ");
    q.exec();
    QString pdf="<br> <h1 style='text-align: center;'><span style='color: #ffcc00;'><em><strong>TABLEAU DE DEPENSES</strong></em></span></p></h1>\n <table style=' width: '100%'; margin-left: auto; margin-right: auto; border='0'>  <tr>  <th>ID </th>       <th>Date </th>  <th>Type </th> <th>Montant </th>     " ;


    while ( q.next()) {
pdf= pdf+ " <br> <tr> <td><p>"+ q.value(0).toString()+"</p></td>   <td><p> " + q.value(1).toString() +"</p></td>   <td><p>" +q.value(2).toString() +" </p></td>   <td><p>"+q.value(3).toString()+"</p></td> <td><p>"+q.value(4).toString()+"</p></td>";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

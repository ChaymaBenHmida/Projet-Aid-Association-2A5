#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dons.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QPrintDialog>
#include<QPrinter>
#include<QPainter>
#include<QTextDocument>
#include<QTextStream>
#include<QSqlRecord>
#include<QFile>
#include<QFileDevice>
#include<historique.h>
#include<QDesktopServices>
#include<QDate>
#include<QDateEdit>
#include<QDateTimeEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tab_dons->setModel(D.afficher());

QRegExp rx("^[A-Z][a-z]{0,10}$");
        ui->le_nom->setValidator(new QRegExpValidator(rx, this));
 ui->le_cin_2->setValidator(new QRegExpValidator(rx, this));
        ui->le_prenom->setValidator(new QRegExpValidator(rx, this));
         ui->recherche->setValidator(new QRegExpValidator(rx, this));

         ui->le_produit->setValidator(new QRegExpValidator(rx, this));
        ui->le_cin->setValidator(new QIntValidator (1,99999999,this));
      ui->le_montant_2->setValidator(new QRegExpValidator(rx, this));
        ui->le_cin_supp->setValidator(new QIntValidator (0,99999999,this));
        ui->le_nom_2->setValidator(new QRegExpValidator(rx, this));
        ui->le_prenom_2->setValidator(new QRegExpValidator(rx, this));
        ui->le_role_2->setValidator(new QIntValidator (0,99999999,this));
         ui->le_produit_2->setValidator(new QIntValidator (0,99999999,this));
         ui->le_montant->setValidator(new QIntValidator (0,99999999,this));
         ui->num1->setValidator(new QIntValidator (0,99999999,this));
         ui->num2->setValidator(new QIntValidator (0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{

   int id=ui->le_cin->text().toInt();
   int montant=ui->le_montant->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
//QString  role=ui->le_role->text();
QString produit=ui->le_produit->text();
QString role =ui->combo->currentText();
QDate dates=ui->date->date();
//enregistrement de l'historique
QFile file("C:/Users/user/Documents/projetQT/historiques.txt");
        if(!file.open(QIODevice::Append)){
            qCritical() << "file not found ";
            qCritical() << file.errorString();

        }
        //qInfo() << "writing file ..";
        QTextStream stream(&file);

        stream << QString() << "ID : " << id << "\n";
        stream << QString() << "Nom : " << nom<< "\n";
        stream << QString() << "Prénom : " <<prenom<< "\n";
        stream << QString() << "Montant : " <<montant<< "\n";
        stream << QString() << "Produit : " << produit<< "\n";
        stream << QString() << "Service : " << role<< "\n";
       // stream << QString << "Date : " << dates<< "\n";
        stream << QString() <<"---------------------------------\n";

        file.close();

   Dons D( id, nom, prenom,role ,produit , montant,dates);

    bool test=D.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("add successful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_dons->setModel(D.afficher());
}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("add failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);;

}

void MainWindow::on_pb_supprimer_clicked()
{
    Dons D1;D1.setid(ui->le_cin_supp->text().toInt());
    bool test=D1.supprimer(D1.getid());
    QMessageBox msgBox;

    if(test)
    {
        ui->tab_dons->setModel(D.afficher());
        QMessageBox::information(nullptr,QObject::tr(" ok"),QObject::tr("suppression effectue \n" "click cancel to exit."),QMessageBox::Cancel);

    }
    else
      {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr(" \n" "suppression non effectue."),QMessageBox::Cancel);

    }

}
void MainWindow::on_tab_recherche_activated(const QModelIndex &index)
{
    QString valu=ui->tab_recherche->model()->data(index).toString();
    QSqlQuery qry ;
     qry.prepare("select id from dons where id ='"+ valu+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_cin_supp->setText(qry.value(0).toString());


        }
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_modifier_clicked()
{


        int id=ui->le_role_2->text().toUInt();

 QString prenom=ui->le_prenom_2->text();
QString nom=ui->le_cin_2->text();
 //QString role=ui->le_nom_2->text();
QString role=ui->combo_modif->currentText();
 int montant=ui->le_produit_2->text().toUInt();
 QString produit=ui->le_montant_2->text();
 QDate dates=ui->date_modif->date();



   Dons D(  id, nom, prenom, role ,produit , montant,dates);
    bool test=D.modifier(id);
    if(test)
    {
        ui->tab_dons->setModel(D.afficher());
        QMessageBox::information(nullptr,QObject::tr(" ok"),QObject::tr("Modification effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    }
    else
      {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Modification non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    }

}

void MainWindow::on_tab_dons_activated(const QModelIndex &index)
{
    QString val=ui->tab_dons->model()->data(index).toString();
    QSqlQuery qry ;
     qry.prepare("select * from dons where id ='"+ val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_cin_2->setText(qry.value(0).toString());
          ui->le_nom_2->setText(qry.value(2).toString());

            ui->le_prenom_2->setText(qry.value(1).toString());

            ui->le_role_2->setText(qry.value(3).toString());
             ui->le_montant_2->setText(qry.value(4).toString());
              ui->le_produit_2->setText(qry.value(5).toString());
                ui->date_modif->setDate(qry.value(6).toDate());

        }
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
    }
}







double MainWindow ::getlineEditNum()
{ num1=ui->num1->text().toDouble();
num2=ui->num2->text().toDouble();

}
void MainWindow::writelabelResult( double tempResult)
{
   ui->result->setText(QString :: number(tempResult));
   result=0;
}
void MainWindow::on_addbutton_clicked()
{getlineEditNum();
result=num1+num2;
writelabelResult( result);

}

void MainWindow::on_Minusvutton_clicked()
{getlineEditNum();
    result=num1-num2;
    writelabelResult( result);
}

void MainWindow::on_multiply_clicked()
{getlineEditNum();
    result=num1*num2;
    writelabelResult( result);
}

void MainWindow::on_divide_clicked()
{getlineEditNum();
    result=num1/num2;
    writelabelResult( result);
}

// preparer la table à imprimer mel base de donnnées
void PrintTable( QPrinter* printer, QSqlQuery&  Query ) {
  QString strStream;
  QTextStream out(&strStream);

  const int rowCount = Query.size();
  const int columnCount = Query.record().count();

  out <<  "<html>\n"
      "<head>\n"
      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
      <<  QString("<title>%1 </title>\n").arg("Dons")
      <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"
      "<table width=110% border=1 cellspacing=10 cellpadding=2 > \n";


  // headers
  out << "<thead><tr bgcolor=#FFE5B4>";
  for (int column = 0; column < columnCount; column++)
    out << QString("<th>%1</th>").arg(Query.record().fieldName(column));
  out << "</tr></thead>\n";

  while (Query.next()) {
    out << "<tr>";
    for (int column = 0; column < columnCount; column++) {
      QString data = Query.value(column).toString();
      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
    }
    out << "</tr>\n";
  }

  out <<  "</table>\n"
      "</body>\n"
      "</html>\n";

  QTextDocument document;
  document.setHtml(strStream);
  document.print(printer);

}

void MainWindow::on_imprimer_clicked()
  {QPrinter printer(QPrinter::HighResolution);
  printer.setOrientation(QPrinter::Portrait);
  printer.setPageSize(QPrinter::A4);
  //printer.setOutputFormat(QPrinter::PdfFormat);
 //  printer.setOutputFileName("e:/file.pdf"); // just for me testing
 QPrintDialog dlg(&printer, 0);
 if(dlg.exec() == QDialog::Accepted) {
  QSqlQuery query;
  query.exec("SELECT * from dons");
  PrintTable(&printer, query);
 }
}




void MainWindow::on_pushButton_5_clicked()
{

  QString nom=ui->recherche->text();

  ui->tab_recherche->setModel(D.recherche_nom(nom)) ;


}



void MainWindow::on_recherche_role_clicked()
{
   // QString role=ui->recherche->text();
    QString role=ui->combo_recherche->currentText();

    ui->tab_recherche->setModel(D.recherche_role(role)) ;
}




void MainWindow::on_pushButton_4_clicked()
{
    QFile file("C:/Users/user/Documents/projetQT/historiques.txt");
        if(!file.open(QIODevice::ReadOnly)){
            qCritical() << "file not found ";
            qCritical() << file.errorString();

        }
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
}

void MainWindow::on_pushButton_clicked()
{
    QString prenom=ui->recherche_prenom->text();

    ui->tab_recherche->setModel(D.recherche_nom(prenom)) ;

}

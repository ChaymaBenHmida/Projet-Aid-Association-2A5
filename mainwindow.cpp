#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->table_E->setModel(E.afficher());
        ui->le_cin->setValidator(new QIntValidator(0,99999999,this));

    }



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{   int cin=ui->le_cin->text().toUInt();

    int telephone=ui->le_tel->text().toUInt();
    int salaire=ui->le_salaire->text().toUInt();
    int jours_de_travail=ui->les_jours->text().toUInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonct->text();

   Employe E(cin,nom,prenom,telephone,jours_de_travail,salaire,fonction);
bool test=E.ajouter();
if(test)
 { QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("add successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("add failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_modifier_clicked()
{
    int cin=ui->modifcin->text().toUInt();
    int tel=ui->modiftel->text().toUInt();
    int jours=ui->modifj->text().toUInt();
    int sal=ui->modifs->text().toUInt();
    QString nom=ui->modifnom->text();
    QString prenom=ui->modifpr->text();
    QString fonction=ui->modiff->text();


Employe E(cin,nom, prenom,tel,jours,sal,fonction);
bool test=E.modifier(cin);
if(test)
{
    ui->table_E->setModel(E.afficher());
    QMessageBox::critical(nullptr,QObject::tr(" ok"),QObject::tr("Modification effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Modification non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}


void MainWindow::on_table_E_activated(const QModelIndex &index)
{
    QString val=ui->table_E->model()->data(index).toString();
    QSqlQuery qry ;
    qry.prepare("select * from employe where cin='"+ val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->modifcin->setText(qry.value(0).toString());
            ui->modifnom->setText(qry.value(1).toString());
            ui->modifpr->setText(qry.value(2).toString());
            ui->modiftel->setText(qry.value(3).toString());
             ui->modifj->setText(qry.value(4).toString());
              ui->modifs->setText(qry.value(5).toString());
               ui->modiff->setText(qry.value(6).toString());
        }
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int cin=ui->cinsupp->text().toInt();
        bool test=E.supprimer(cin);
        if(test)
        { ui->table_E->setModel(E.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue\n" "click cancel to exit."),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

        }
}

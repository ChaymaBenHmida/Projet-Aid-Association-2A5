#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "activite.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QTableView>
#include <QRegExpValidator>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_act->setModel(A.afficher()); //affichage

//controle de saisie sur le champ id
ui->le_id->setValidator(new QIntValidator(100, 99999999, this));
ui->le_modifid->setValidator(new QIntValidator(100, 99999999, this));
ui->le_sup->setValidator(new QIntValidator(100, 99999999, this));

//controle de saisie sur le champ nom
        QRegExp rxnom("\\b[a-zA-Z0-9]{2,10}\\b");
        QRegExpValidator *valinom =new QRegExpValidator(rxnom,this);
        ui->le_nom->setValidator(valinom);
        ui->le_modifnom->setValidator(valinom);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajout_clicked()
{
    int idA=ui->le_id->text().toInt();
    QString nomA=ui->le_nom->text();
    QString dateA=ui->le_date->text();
     Activite A(idA,nomA,dateA);

     bool test=A.ajouter();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("ajout avec succes");
     else
        msgbox.setText("echec d'ajout");
     msgbox.exec();
     ui->tab_act->setModel(A.afficher());
}

void MainWindow::on_pushButton_7_clicked() //suppression
{
  Activite A1 ;
  A1.setidA(ui->le_sup->text().toInt());
    bool test=A1.supprimer(A1.getidA());
    QMessageBox msgBox;
    if (test)
        msgBox.setText("suppression avec succés");
        else
     msgBox.setText("echec de suppression");
     msgBox.exec();

}


void MainWindow::on_on_pb_modifier_clicked_clicked()
{
    int idA=ui->le_modifid->text().toInt();
    QString nomA=ui->le_modifnom->text();
    QString dateA=ui->le_modifid_2->text();

     Activite A(idA,nomA,dateA);
     bool test=A.modifier();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("modification avec succés");
     else
        msgbox.setText("echec de modification");
     msgbox.exec();
}

void MainWindow::on_pb_affichierExecuter_clicked()
{
    ui->tab_act->setModel(A.afficher());
}


void MainWindow::on_recherche_clicked()
{
        QString nomA=ui->le_recherche->text();
        ui->tab_act->setModel(A.recherche(nomA)) ;
}

void MainWindow::on_tab_act_activated(const QModelIndex &index)
{
    QString val=ui->tab_act->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from ACTIVITE where idA='"+val+"' or nomA='"+val+"' or dateA='"+val+"' " );
        if(qry.exec())
        {
        while(qry.next())
        {
            ui->le_modifid->setText((qry.value(0).toString()));
            ui->le_modifnom->setText(qry.value(1).toString());
            ui->le_modifid_2->setText(qry.value(2).toString());

         }
        }
}

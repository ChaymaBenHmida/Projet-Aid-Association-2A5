#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "handicape.h"
#include <QMessageBox>
#include "secdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table_handicape->setModel(h.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{   int id=ui->id->text().toUInt();
    int age=ui->age->text().toUInt();
    int tel=ui->tel->text().toUInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();

    handicape h(id,nom,prenom,age,tel);
bool test =h.ajouter();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajouter effectue\n" "click cancel to exit."),QMessageBox::Cancel);
}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}




void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->id_modi_supp->text().toInt();
    bool test=h.supprimer(id);
    if(test)
    { ui->table_handicape->setModel(h.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    }

}





void MainWindow::on_pushButton_clicked()
{
    secdialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();
}


void MainWindow::on_pb_update_clicked()
{
    int id=ui->i->text().toUInt();
    int age=ui->a->text().toUInt();
    int tel=ui->t->text().toUInt();
    QString nom=ui->n->text();
    QString prenom=ui->p->text();

    handicape h(id,nom,prenom,age,tel);
bool test= h.modifier();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n" "click cancel to exit."),QMessageBox::Cancel);
}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Modification non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}

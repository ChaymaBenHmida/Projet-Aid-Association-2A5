#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "handicape.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->table_handicape->setModel(h.afficher());
ui->id->setValidator(new QIntValidator(0,9999,this));
ui->age->setValidator(new QIntValidator(0,18,this));
ui->tel->setValidator(new QIntValidator(0,99999999,this));


QRegExp rx("^[A-Z][a-z]{0,10}$");
ui->nom->setValidator(new QRegExpValidator(rx, this));
ui->prenom->setValidator(new QRegExpValidator(rx, this));
ui->txt_nom->setValidator(new QRegExpValidator(rx, this));
ui->txt_prenom->setValidator(new QRegExpValidator(rx, this));


ui->txt_id->setValidator(new QIntValidator(0,9999,this));
ui->txt_age->setValidator(new QIntValidator(0,18,this));
ui->txt_tel->setValidator(new QIntValidator(0,99999999,this));


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
{  ui->table_handicape->setModel(h.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajouter effectue\n" "click cancel to exit."),QMessageBox::Cancel);
}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}




void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->txt_id->text().toInt();
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




void MainWindow::on_table_handicape_activated(const QModelIndex &index)
{
    QString val=ui->table_handicape->model()->data(index).toString();
QSqlQuery qry ;
qry.prepare("select * from handicape where id='"+ val+"'");

if(qry.exec())
{
    while(qry.next())
    {
        ui->txt_id->setText(qry.value(0).toString());
        ui->txt_nom->setText(qry.value(1).toString());
        ui->txt_prenom->setText(qry.value(2).toString());
        ui->txt_age->setText(qry.value(3).toString());
         ui->txt_tel->setText(qry.value(4).toString());
    }
}
else {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
}

}








void MainWindow::on_pb_modifier_2_clicked()
{
    int id=ui->txt_id->text().toUInt();
    int age=ui->txt_age->text().toUInt();
    int tel=ui->txt_tel->text().toUInt();
    QString nom=ui->txt_nom->text();
    QString prenom=ui->txt_prenom->text();

    handicape h(id,nom,prenom,age,tel);

bool test= h.modifier(id);
if(test)
{
    QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("Modification  effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    ui->table_handicape->setModel(h.afficher());
}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Modification non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}

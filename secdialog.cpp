#include "secdialog.h"
#include "ui_secdialog.h"
#include "handicape.h"
#include <QMessageBox>

secdialog::secdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    ui->setupUi(this);
}

secdialog::~secdialog()
{
    delete ui;
}

void secdialog::on_pb_modifier_clicked()
{
    int id=ui->id_modi->text().toUInt();
    int age=ui->age_modi->text().toUInt();
    int tel=ui->tel_modi->text().toUInt();
    QString nom=ui->nom_modi->text();
    QString prenom=ui->prenom_modi->text();

    handicape h(id,nom,prenom,age,tel);
bool test =h.modifier();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n" "click cancel to exit."),QMessageBox::Cancel);
}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Modification non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}

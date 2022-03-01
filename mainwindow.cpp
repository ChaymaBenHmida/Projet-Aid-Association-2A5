#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{int id=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    int telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    int jours_de_travail=ui->les_jours->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonct->text();

   Employe E(id, cin,telephone,jours_de_travail,nom, prenom,fonction, salaire);
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


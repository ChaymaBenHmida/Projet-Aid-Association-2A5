#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "handicape.h"
#include "excel.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <QDateEdit>
#include <QDate>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).


    ui->datee->setModel(h.afficher_rdv());
ui->comboBox->setModel(h.afficher_id());


ui->table_handicape->setModel(h.afficher());
ui->id->setValidator(new QIntValidator(0,9999,this));
ui->age->setValidator(new QIntValidator(0,18,this));
ui->tel->setValidator(new QIntValidator(11111111,99999999,this));


QRegExp rx("^[A-Z][a-z]{0,10}$");
ui->nom->setValidator(new QRegExpValidator(rx, this));
ui->prenom->setValidator(new QRegExpValidator(rx, this));
ui->txt_nom->setValidator(new QRegExpValidator(rx, this));
ui->txt_prenom->setValidator(new QRegExpValidator(rx, this));


ui->txt_id->setValidator(new QIntValidator(0,9999,this));
ui->txt_age->setValidator(new QIntValidator(0,18,this));
ui->txt_tel->setValidator(new QIntValidator(11111111,99999999,this));


//clear button
ui->txt_nom->setClearButtonEnabled(true);
ui->txt_prenom->setClearButtonEnabled(true);
ui->txt_age->setClearButtonEnabled(true);
ui->txt_tel->setClearButtonEnabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}



/*********************************************** ajouter *******************************************************/

void MainWindow::on_pb_ajouter_clicked()
{   int id=ui->id->text().toUInt();
    int age=ui->age->text().toUInt();
    int tel=ui->tel->text().toUInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
   QString img=ui->img_name->text();

    handicape h(id,nom,prenom,age,tel,img);
bool test =h.ajouter();
if(test)
{  ui->table_handicape->setModel(h.afficher());
    h.notifications_ajouter();
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajouter effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}



/*********************************************** supprimer *******************************************************/

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->txt_id->text().toInt();
    bool test=h.supprimer(id);
    if(test)
    { ui->table_handicape->setModel(h.afficher());
        h.notifications_supprimer();
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    }

}



/*********************************************** affichage(modifier...) *******************************************************/

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
         ui->txt_loc_img->setText(qry.value(5).toString());


         QString filename = ui->txt_loc_img->text();

        if(QString::compare(filename,QString())!=0)
        {
            QImage image;
            bool valid=image.load(filename);
            if(valid){

                image=image.scaledToWidth(ui->image->width(),Qt::SmoothTransformation);
                ui->txt_img->setPixmap(QPixmap::fromImage(image));

            }
            else
            {
                QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
            }
        }


    }
}
else {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
}

}






/*********************************************** modifier *******************************************************/


void MainWindow::on_pb_modifier_2_clicked()
{
    int id=ui->txt_id->text().toUInt();
    int age=ui->txt_age->text().toUInt();
    int tel=ui->txt_tel->text().toUInt();
    QString nom=ui->txt_nom->text();
    QString prenom=ui->txt_prenom->text();
    QString img=ui->txt_loc_img->text();

    handicape h(id,nom,prenom,age,tel,img);

bool test= h.modifier(id);
if(test)
{ h.notifications_modifier();
    QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("Modification  effectue\n" "click cancel to exit."),QMessageBox::Cancel);

    ui->table_handicape->setModel(h.afficher());
}
else
  {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Modification non effectue\n" "click cancel to exit."),QMessageBox::Cancel);

}
}

void MainWindow::on_pb_clear_clicked()
{
    ui->id->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->age->clear();
    ui->tel->clear();
}

/*********************************************** rechercher *******************************************************/


void MainWindow::on_pushButton_clicked()
{
    QString nom = ui->input_recherche->text();
    if(nom=="")
    {
        ui->table_rech->setModel(h.afficher());
    }
    else
    {
        if( ui->rech_age->isChecked())
        {
            ui->table_rech->setModel(h.recherche_age(nom));
        }
        if( ui->rech_nom->isChecked())
        {
            ui->table_rech->setModel(h.recherche_nom(nom));
        }
        if( ui->rech_prenom->isChecked())
        {
            ui->table_rech->setModel(h.recherche_prenom(nom));
        }
    }

}

void MainWindow::on_rech_prenom_stateChanged(int arg1)
{
    if(ui->rech_prenom->isChecked())
    {
    ui->rech_age->setDisabled(true);
    ui->rech_nom->setDisabled(true);
    }
    else
    {
        ui->rech_age->setDisabled(false);
        ui->rech_nom->setDisabled(false);

    }
}


void MainWindow::on_rech_nom_stateChanged(int arg1)
{
    if(ui->rech_nom->isChecked())
    {
    ui->rech_age->setDisabled(true);
    ui->rech_prenom->setDisabled(true);
    }
    else
    {
        ui->rech_age->setDisabled(false);
        ui->rech_prenom->setDisabled(false);

    }
}

void MainWindow::on_rech_age_stateChanged(int arg1)
{
    if(ui->rech_age->isChecked())
    {
    ui->rech_nom->setDisabled(true);
    ui->rech_prenom->setDisabled(true);
    }
    else
    {
        ui->rech_nom->setDisabled(false);
        ui->rech_prenom->setDisabled(false);

    }
}


/*********************************************** imprimer *******************************************************/

void MainWindow::on_pb_print_clicked()
{
  QModelIndex index=ui->table_rech->currentIndex();
 QString  info = index.data(Qt::DisplayRole).toString();
 QSqlQuery view;
 QPlainTextEdit text;
  handicape h;
QString id,nom,prenom,age,tel;

        view=h.editview(info);
        //view.next();
        while ( view.next()) {


id=view.value(0).toString();
nom=view.value(1).toString();
prenom=view.value(2).toString();
age=view.value(3).toString();
tel=view.value(4).toString();



        text.appendPlainText("");
        text.appendPlainText("");


        text.appendPlainText("ID: "+id+"");

        text.appendPlainText("nom: "+nom+"");

        text.appendPlainText("prenom: "+prenom+"");

        text.appendPlainText("age: "+age+"");

        text.appendPlainText("tel: "+tel+"");

}
        QPrinter printer;
            printer.setPrinterName("Print");
            QPrintDialog dlg(&printer,this);
            if (dlg.exec() == QDialog::Rejected)
            {
                return;
            }
            text.print(&printer);


}




void MainWindow::on_pb_imprimer_handicape_clicked()
{
     QPlainTextEdit text;
     QString id,nom,prenom,age,tel;
     id=ui->txt_id->text();
     nom=ui->txt_nom->text();
     prenom=ui->prenom->text();
     age=ui->txt_age->text();
     tel=ui->txt_tel->text();



text.appendPlainText("ID: "+id+"");
text.appendPlainText("nom: "+nom+"");
text.appendPlainText("prenom: "+prenom+"");
text.appendPlainText("age: "+age+"");
text.appendPlainText("tel: "+tel+"");

QPrinter printer;
    printer.setPrinterName("Print");
    QPrintDialog dlg(&printer,this);
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }
    text.print(&printer);


}



/*********************************************** EXCEL *******************************************************/

void MainWindow::on_pb_excel_clicked()
{



    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->table_handicape);

            obj.addField(0, "ID", "char(20)");
            obj.addField(1, "Nom", "char(20)");
            obj.addField(2, "Prenom", "char(20)");
            obj.addField(3, "Age", "char(20)");
            obj.addField(4, "Tel", "char(20)");



            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"),
                                         QString(tr("%1 records exported!")).arg(retVal)
                                         );
            }
}



/*********************************************** insertion image(ajout)  *******************************************************/


void MainWindow::on_pb_img_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(""));

   if(QString::compare(filename,QString())!=0)
   {QImage image;
       bool valid=image.load(filename);
       if(valid){

           ui->img_name->setText(filename);
           image=image.scaledToWidth(ui->image->width(),Qt::SmoothTransformation);
           ui->image->setPixmap(QPixmap::fromImage(image));

       }
       else
       {
           QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
       }
   }
}


/*********************************************** insertion image(modifier)  *******************************************************/

void MainWindow::on_pb_modifier_img_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(""));

   if(QString::compare(filename,QString())!=0)
   {QImage image;
       bool valid=image.load(filename);
       if(valid){

           ui->txt_loc_img->setText(filename);
           image=image.scaledToWidth(ui->image->width(),Qt::SmoothTransformation);
           ui->txt_img->setPixmap(QPixmap::fromImage(image));

       }
       else
       {
           QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
       }
   }
}


/******** test rdv *****/

/*****ajouter rdv*******/
void MainWindow::on_pushButton_2_clicked()
{
   QString rdvv=ui->rdvv->date().toString("dd.MM.yyyy");
int id=ui->comboBox->currentText().toUInt();

//QDate rdvv=ui->rdvv->date();
    QSqlQuery query;
 //query.bindValue(":rdvv",rdvv);
    query.prepare("INSERT INTO  test(rdvv,id)""values(?,?)");
    query.addBindValue(rdvv);
query.addBindValue(id);


if(!query.exec())
                              {
                                 //QMessageBox::text(this, "Erreur requête");
                              }
ui->datee->setModel(h.afficher_rdv());




}



/**************************************************************************************************************************/

void MainWindow::on_datee_activated(const QModelIndex &index)
{
/*
//ui->datee->setModel(h.afficher_rdv());




QString val=ui->datee->model()->data(index).toString();
QSqlQuery qry ;
qry.prepare("select rdvv from test where rdvv='"+ val+"'");


if(qry.exec())
{
while(qry.next())
{
    ui->date_rdvv->setText(qry.value(0).toString());
   QString date=qry.value(0).toString();

   QDate date_entree1 =qry.value(0).toDate(); //transformer date ml string lel type date
   QDate date_actuelle = QDate::currentDate(); //date lyoumm
QString date_lyoum=date_actuelle.toString("dd.MM.yyyy");
QDate lyoum=QDate::fromString(date_lyoum, "dd.MM.yyyy");

QString dd=date_actuelle.toString();
ui->date_lyoum->setText(date_lyoum);
QDate test=dayOfWeek(lyoum);
ui->label_rdv->setText(test.toString());

   if( (date_entree1)==(lyoum))
               {
                 //  ui->label_rdv->setText("egale");
               }

               else if ((date_entree1)>(lyoum))
               {
                 //  ui->label_rdv->setText("akber");
               }else{
       //ui->label_rdv->setText("asgher");
   }

}
}else {
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
}

*/

}




void MainWindow::on_comboBox_activated(const QString &arg1)
{

}


void MainWindow::on_pushButton_3_clicked()
{

    QModelIndex index=ui->datee->currentIndex();
   QString  info = index.data(Qt::DisplayRole).toString();
   QSqlQuery view;
   QPlainTextEdit text;
    handicape h;



          view=h.editview_rdv(info);
 int i=0;
          while ( view.next()) {

             // ui->date_rdvv->setText(view.value(0).toString());
             QString date=view.value(0).toString();
QDate date_entree1=QDate::fromString(date, "dd.MM.yyyy");

             //QDate date_entree1 =view.value(0).toDate(); //transformer date ml string lel type date

             QDate date_actuelle = QDate::currentDate(); //date lyoumm
          QString date_lyoum=date_actuelle.toString("dd.MM.yyyy");
          QDate lyoum=QDate::fromString(date_lyoum, "dd.MM.yyyy");


          ui->date_lyoum->setText(date_lyoum);

             if( (date_entree1)==(lyoum))
                         { i++;
                             ui->label_rdv->setText("egale");
                         }

                         else
                         {
                             ui->label_rdv->setText("different");
                         }

          }
          /*******notification rdv aujourdhui******/
          QString ii=QString::number(i);
          ui->date_rdvv->setText(ii);

          if(i!=0){
          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

          notifyIcon->show();
          notifyIcon->showMessage("Gestion des RDVs "," RDV pour aujourd hui ",QSystemTrayIcon::Information,15000);
          }else {
              QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

              notifyIcon->show();
              notifyIcon->showMessage("Gestion des RDVs ","Pas de RDV pour aujourd hui ",QSystemTrayIcon::Information,15000);

}





}

/**********************************ARDUINOOOO*************************************************/




void MainWindow::on_pushButton_4_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino

}


void MainWindow::on_pushButton_9_clicked()
{

    A.write_to_arduino("0");  //envoyer 0 à arduino
}

/*
void MainWindow::on_label_11_linkActivated(const QString &link)
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_11->setText("Nombre ATTEIN"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_11->setText("Nombre NON ATTEIN");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}
*/

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_11->setText("Nembre ATTEIN"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_11->setText("Nembre NON ATTEIN");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void MainWindow::on_update_label_linkActivated(const QString &link)
{

}

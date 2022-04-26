//*****include karim*****
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "depenses.h"
#include "history.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QDate>
#include <QSqlQuery>
#include <QDesktopServices>
#include <QFile>
#include"QTimer"
#include<QDebug>

//*****include tasnim*****

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
#include <QDate>
#include "QMessageBox"

//*****include chayma*****

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "activite.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QTableView>
#include <QRegExpValidator>
#include<QSqlQuery>
#include"historique.h"
#include<QPlainTextEdit>
#include<QPrintDialog>
#include <QPrinter>

#include<QTcpServer>
#include<QTcpSocket>
#include<QWidget>
#include<QWidgetAction>

#include<QTranslator>
#include<QInputDialog>
#include<QStringList>
#include<QIntValidator>
#include<QThread>

//*****include maryem*****

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

//*****include chahrazed*****

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
// jdoood-------------------
#include <QUrl>
#include <QDesktopServices>
//-----------------
#include <QIntValidator>
#include <QRegExpValidator>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include "arduino.h"
QString days="";

//*****init karim*****

double firstNum;
bool user_is_typing_secondNumber=false;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//*****controle de saisie karim + animation page +  notification systeme init+ calculatrice init *****
    ui->lineEdit_montant->setValidator(new QIntValidator (1,99999999,this));
    ui->lineEdit_id_depenses->setValidator(new QIntValidator (1,99999999,this));

        ui->stackedWidget_2->setAnimation(QEasingCurve::Type::OutQuart);
        ui->stackedWidget_2->setSpeed(650);
        connect(ui->precedent,&QAbstractButton::clicked,[this]{
            if(ui->stackedWidget_2->slideInPrev()){
                ui->precedent->setEnabled(false);
                ui->suivant->setEnabled(false);
            }
        });
        connect(ui->suivant,&QAbstractButton::clicked,[this]{
            if(ui->stackedWidget_2->slideInNext()){
                ui->precedent->setEnabled(false);
               ui->suivant->setEnabled(false);
            }
        });
        connect(ui->stackedWidget_2,&SlidingStackedWidget::animationFinished,[this]{
            ui->precedent->setEnabled(true);
            ui->suivant->setEnabled(true);
        });
        //######################################################
        ui->stackedWidget_3->setAnimation(QEasingCurve::Type::OutQuart);
        ui->stackedWidget_3->setSpeed(650);
        connect(ui->precedent_2,&QAbstractButton::clicked,[this]{
            if(ui->stackedWidget_3->slideInPrev()){
                ui->precedent_2->setEnabled(false);
                ui->suivant_2->setEnabled(false);
            }
        });
        connect(ui->suivant_2,&QAbstractButton::clicked,[this]{
            if(ui->stackedWidget_3->slideInNext()){
                ui->precedent_2->setEnabled(false);
               ui->suivant_2->setEnabled(false);
            }
        });
        connect(ui->stackedWidget_3,&SlidingStackedWidget::animationFinished,[this]{
            ui->precedent_2->setEnabled(true);
            ui->suivant_2->setEnabled(true);
        });

        //######################################################
        ui->stackedWidget_4->setAnimation(QEasingCurve::Type::OutQuart);
        ui->stackedWidget_4->setSpeed(650);
        connect(ui->precedent_3,&QAbstractButton::clicked,[this]{
            if(ui->stackedWidget_4->slideInPrev()){
                ui->precedent_3->setEnabled(false);
                ui->suivant_3->setEnabled(false);
            }
        });
        connect(ui->suivant_3,&QAbstractButton::clicked,[this]{
            if(ui->stackedWidget_4->slideInNext()){
                ui->precedent_3->setEnabled(false);
               ui->suivant_3->setEnabled(false);
            }
        });
        connect(ui->stackedWidget_4,&SlidingStackedWidget::animationFinished,[this]{
            ui->precedent_3->setEnabled(true);
            ui->suivant_3->setEnabled(true);
        });


    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setVisible(true);
    //ui->tableView->setModel(Stmp.afficher());
    show_table();

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

//*****Controle de saisie tasnim + Arduino*****


    int ret=INO.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< INO.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<INO.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }



        ui->tab_dons->setModel(D.afficher());

        QRegExp rx("^[A-Z][a-z]{0,10}$");
                ui->le_nom->setValidator(new QRegExpValidator(rx, this));
         ui->le_cin_2->setValidator(new QRegExpValidator(rx, this));
                ui->le_prenom->setValidator(new QRegExpValidator(rx, this));
                 ui->recherche->setValidator(new QRegExpValidator(rx, this));

                 ui->le_produit->setValidator(new QRegExpValidator(rx, this));
                ui->le_cin->setValidator(new QIntValidator (1,99999999,this));
              ui->le_montant_2->setValidator(new QIntValidator (0,99999999,this));
                ui->le_cin_supp->setValidator(new QIntValidator (0,99999999,this));
                ui->le_nom_2->setValidator(new QRegExpValidator(rx, this));
                ui->le_prenom_2->setValidator(new QRegExpValidator(rx, this));
                //ui->le_role_2->setValidator(new QIntValidator (0,99999999,this));
                 ui->le_produit_2->setValidator(new QRegExpValidator(rx, this));
                 ui->le_montant->setValidator(new QIntValidator (0,99999999,this));
                 ui->num1->setValidator(new QIntValidator (0,99999999,this));
                 ui->num2->setValidator(new QIntValidator (0,99999999,this));


//*****Controle de saisie chayma*****


        ui->tab_act->setModel(A.afficher()); //affichage

    //controle de saisie sur le champ id
        ui->le_id->setValidator(new QIntValidator(100, 99999999, this));
        ui->le_modifid->setValidator(new QIntValidator(100, 99999999, this));
        ui->le_sup->setValidator(new QIntValidator(100, 99999999, this));

    //controle de saisie sur le champ nom
            QRegExp rxnom("\\b[a-zA-Z0-9]{2,20}\\b");
            QRegExpValidator *valinom =new QRegExpValidator(rxnom,this);
            ui->le_nom->setValidator(valinom);
            ui->le_modifnom->setValidator(valinom);

    //controle de saisie sur le champ Statu
                ui->le_statu->setValidator(new QIntValidator(100, 9, this));
                ui->le_statuModif->setValidator(new QIntValidator(100, 9, this));

               ui->le_statu->setValidator(new QIntValidator(0,2,this));
               ui->le_statuModif->setValidator(new QIntValidator(0,2,this));

    //controle de saisie sur le champ description
               QRegExp rxdesc("\\b[a-zA-Z0-9- ]{5,30}\\b");
               QRegExpValidator *validesc =new QRegExpValidator(rxdesc,this);
               ui->le_description->setValidator(validesc);
               ui->le_descriptionModif->setValidator(validesc);

    //controle de saisie sur le champ date
               QRegExp rxdate("\\b[0-9- ]{10,10}\\b");
               QRegExpValidator *validate =new QRegExpValidator(rxdate,this);
               ui->le_date_3->setValidator(validate);
               ui->le_modifDate->setValidator(validate);


 //*****Controle de saisie maryem + Arduino*****


               ui->datee->setModel(h.afficher_rdv());
               ui->comboBox_2->setModel(h.afficher_id());


               ui->table_handicape->setModel(h.afficher());
               ui->id->setValidator(new QIntValidator(0,9999,this));
               ui->age->setValidator(new QIntValidator(0,18,this));
               ui->tel->setValidator(new QIntValidator(11111111,99999999,this));


               QRegExp rx1("^[A-Z][a-z]{0,10}$");
               ui->nom->setValidator(new QRegExpValidator(rx1, this));
               ui->prenom->setValidator(new QRegExpValidator(rx1, this));
               ui->txt_nom->setValidator(new QRegExpValidator(rx1, this));
               ui->txt_prenom->setValidator(new QRegExpValidator(rx1, this));


               ui->txt_id->setValidator(new QIntValidator(0,9999,this));
               ui->txt_age->setValidator(new QIntValidator(0,18,this));
               ui->txt_tel->setValidator(new QIntValidator(11111111,99999999,this));


               //clear button
               ui->txt_nom->setClearButtonEnabled(true);
               ui->txt_prenom->setClearButtonEnabled(true);
               ui->txt_age->setClearButtonEnabled(true);
               ui->txt_tel->setClearButtonEnabled(true);

//*****Controle de saisie chahrazed +arduino*****

               //---------------------------------------------------ARDUINOO----------------------------------------------------------------------------------------------

               int ret1=ARD.connect_arduino(); // lancer la connexion à arduino
               switch(ret1){
               case(0):qDebug()<< "arduino is available and connected to : "<< ARD.getarduino_port_name();
                   break;
               case(1):qDebug() << "arduino is available but not connected to :" <<ARD.getarduino_port_name();
                  break;
               case(-1):qDebug() << "arduino is not available";
               }
                QObject::connect(ARD.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                //le slot update_label suite à la reception du signal readyRead (reception des données).
               // --------------------------------------------------------------------------------------------------------------------------------------------

               ui->table_E->setModel(E.afficher());
               ui->le_cin_3->setValidator(new QIntValidator(0,99999999,this));
                       ui->le_tel->setValidator(new QIntValidator(0,99999999,this));
                      // ui->les_jours->setValidator(new QIntValidator(0,7,this));
                        ui->le_salaire->setValidator(new QIntValidator(0,9999999,this));
                       QRegExp rx2("^[A-Z][a-z]{0,10}$");
                       ui->le_nom_4->setValidator(new QRegExpValidator(rx2, this));

                       ui->le_prenom_3->setValidator(new QRegExpValidator(rx2, this));
                       ui->le_fonct->setValidator(new QRegExpValidator(rx2, this));
                ui->modifnom->setValidator(new QRegExpValidator(rx2, this));
                 ui->modifpr->setValidator(new QRegExpValidator(rx2, this));
                    ui->modifs->setValidator(new QIntValidator(0,9999999,this));

                  ui->modifcin->setValidator(new QIntValidator(0,99999999,this));
                  ui->modiftel->setValidator(new QIntValidator(0,99999999,this));
                 // ui->modifj->setValidator(new QIntValidator(0,7,this));



}




MainWindow::~MainWindow()
{
    delete ui;
}

//*****Menu*****

void MainWindow::on_Acceuil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Handicapes_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Activites_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Dons_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Depenses_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_Quitter_clicked()
{
        this->close();
}


//*****Gestion depenses*****


//crud

void MainWindow::on_ajouter_clicked()
{

        int id_depenses=ui->lineEdit_id_depenses->text().toInt();
        QDate date_depenses=ui->lineEdit_date_depenses->date();
        QString type_depenses=ui->lineEdit_type_depenses->currentText();
        int montant=ui->lineEdit_montant->text().toInt();
        History h;
          h.save("id_depenses:"+ui->lineEdit_id_depenses->text(),"date_depenses :"+ui->lineEdit_date_depenses->text(),"type_depenses :"+ui->lineEdit_type_depenses->currentText(),"montant :"+ui->lineEdit_montant->text());
        depenses D(id_depenses,date_depenses,type_depenses,montant);
        bool test=D.ajouter();
        if (test)
        { QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("Ajout effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            show_table();
            clear_form();

            if(type_depenses=="Materiels")

            {
                mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté des Materiaux"));
            }

            else if(type_depenses=="Medicaments")

            {
                mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté des Medicaments"));
            }

            else if(type_depenses=="Repas")

            {
                mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté des Repas"));
            }

            else if(type_depenses=="Evenements")

            {
                mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez reservé pour un evenement"));
            }

            else if(type_depenses=="Salaires")

            {
                mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez envoyé les salaires"));
            }

            else

            {
                mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté autres choses"));
            }

            }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                QObject::tr("Ajout échoué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }


void MainWindow::on_supprimer_clicked()
{
    depenses D1; D1.setid_depenses(ui->lineEdit_id_depenses->text().toInt());
    bool test=D1.supprimer(D1.getid_depenses());
    if (test)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        show_table();
        clear_form();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Suppression échoué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_clicked()
{
    int id_depenses=ui->lineEdit_id_depenses->text().toInt();
    QDate date_depenses=ui->lineEdit_date_depenses->date();
    QString type_depenses=ui->lineEdit_type_depenses->currentText();
    int montant=ui->lineEdit_montant->text().toInt();
    depenses D(id_depenses,date_depenses,type_depenses,montant);



bool ok=D.modifier(id_depenses,date_depenses,type_depenses,montant);
if(ok)
{

    QMessageBox::information(nullptr, QObject::tr("succes"),
                QObject::tr(" modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    show_table();
    clear_form();

    if(type_depenses=="Materiels")

    {
        mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté des Materiaux"));
    }

    else if(type_depenses=="Medicaments")

    {
        mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté des Medicaments"));
    }

    else if(type_depenses=="Repas")

    {
        mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté des Repas"));
    }

    else if(type_depenses=="Evenements")

    {
        mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez reservé pour un evenement"));
    }

    else if(type_depenses=="Salaires")

    {
        mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez envoyé les salaires"));
    }

    else

    {
        mSystemTrayIcon->showMessage(tr("Alerte"),tr("vous avez acheté autres choses"));
    }


}
else
    QMessageBox::critical(nullptr, QObject::tr("fail"),
                QObject::tr(" non modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



}




//Clear


void MainWindow::clear_form( ) {

    ui->lineEdit_id_depenses->clear();
    ui->lineEdit_date_depenses->clearMaximumDate();
    ui->lineEdit_type_depenses->setCurrentIndex(0);
    ui->lineEdit_montant->clear();

}

void MainWindow::on_clear_clicked()
{
    clear_form();
}


//Recherche Avancée


void MainWindow::show_table(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableView->setModel(proxy);

}

void MainWindow::on_chercher_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    sel_col=ui->comboBox->currentIndex();
    proxy->setFilterKeyColumn(sel_col); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}


//Remplir les variables du tableau


void MainWindow::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from DEPENSES where id_depenses= :id_depenses");
    query.bindValue(":id_depenses", selected);
    query.exec();
    while(query.next()){

  ui->lineEdit_id_depenses->setText(query.value(0).toString()); //line edit
  ui->lineEdit_date_depenses->setDate(query.value(1).toDate());
  ui->lineEdit_type_depenses->setCurrentText(query.value(2).toString()); //combobox
  ui->lineEdit_montant->setText(query.value(3).toString());

    }

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    selected=ui->tableView->model()->data(index).toString();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    fill_form(selected);
}


//Stats


void MainWindow::on_stats_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                model->setQuery("select * from DEPENSES where montant < 100 ");
                                float montant1=model->rowCount();
                                model->setQuery("select * from DEPENSES where montant  between 100 and 999 ");
                                float montant2=model->rowCount();
                                model->setQuery("select * from DEPENSES where montant >=1000 ");
                                float montant3=model->rowCount();
                                float total=montant1+montant2+montant3;
                                QString a=QString("moins de 100 dt "+QString::number(((montant1)/total)*100,'f',2)+"%" );
                                QString b=QString("entre 100et 999dt "+QString::number(((montant2)/total)*100,'f',2)+"%" );
                                QString c=QString("1000 et plus "+QString::number(((montant3)/total)*100,'f',2)+"%" );
                                QPieSeries *series = new QPieSeries();
                                series->append(a,montant1);
                                series->append(b,montant2);
                                series->append(c,montant3);
        if (montant1!=0)
                        {QPieSlice *slice = series->slices().at(0);
                         slice->setLabelVisible();
                         slice->setPen(QPen());}
                        if ( montant2!=0)
                        {

                                 QPieSlice *slice1 = series->slices().at(1);
                                 //slice1->setExploded();
                                 slice1->setLabelVisible();
                        }
                        if(montant3!=0)
                        {
                                 // Add labels to rest of slices
                                 QPieSlice *slice2 = series->slices().at(2);
                                 //slice1->setExploded();
                                 slice2->setLabelVisible();
                        }
                                // Create the chart widget
                                QChart *chart = new QChart();
                                // Add data to chart with title and hide legend
                                chart->addSeries(series);
                                chart->setTitle("statistique "+ QString::number(total));
                                chart->legend()->hide();
                                // Used to display the chart
                                QChartView *chartView = new QChartView(chart);
                                chartView->setRenderHint(QPainter::Antialiasing);
                                chartView->resize(1000,500);
                                chartView->show();
}

//PDF

void MainWindow::on_pushButton_PDF_clicked()
{
    depenses D;
    D.creerpdf();
}

//Historique

void MainWindow::on_history_clicked()
    {

    QFile file("C:/Users/soyre/Documents/integration_finale/his.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "file not found ";
        qCritical() << file.errorString();

    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());

    }

//Calculatrice

void MainWindow::digit_pressed()
{
   // qDebug() << "test";
    QPushButton * button = (QPushButton *)sender();
    QString input;
    double labelnumber;

    if((ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked()) && (!user_is_typing_secondNumber))
    {
        user_is_typing_secondNumber=true;
        labelnumber = button->text().toDouble();
        input = QString::number(labelnumber,'g',15);
    }

    else
    {
        if(ui->label_10->text().contains(".") && button->text() == "0")
        {
            input=ui->label_10->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label_10->text() + button->text()).toDouble();
            input = QString::number(labelnumber,'g',15);
        }
        //labelnumber = (ui->label->text() + button->text()).toDouble();
    }
    ui->label_10->setText(input);

}

void MainWindow::on_pushButton_dot_released()
{
    // check for appearance of decimal, exit function if there is one
         if(ui->label_10->text().contains(".")){

                 return;
         }
    ui->label_10->setText(ui->label_10->text() + ".");
    //check for extra decimal
}

void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double labelnumber;
    QString input;

    if(button->text() == "+/-")
    {
        labelnumber = (ui->label_10->text()).toDouble();
        labelnumber *= -1;
        input = QString::number(labelnumber,'g',15);
        ui->label_10->setText(input);
    }

    else if(button->text() == "%")
    {
        labelnumber = (ui->label_10->text()).toDouble();
        labelnumber *= 0.01;
        input = QString::number(labelnumber,'g',15);
        ui->label_10->setText(input);
    }

    //error correction codse is still missing
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    user_is_typing_secondNumber=false;

    ui->label_10->setText("0");
    //Updating the equation label
    ui->label_9->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelnumber,secondNum;
    QString input;
    labelnumber=0;
    QString symbol;
    secondNum = ui->label_10->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelnumber = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);
        symbol = " + ";
    }

    else if(ui->pushButton_minus->isChecked())
    {
        labelnumber = firstNum - secondNum;
        ui->pushButton_minus->setChecked(false);
        symbol = " - ";
    }

    else if(ui->pushButton_multiply->isChecked())
    {
        labelnumber = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);
        symbol = " x ";
    }

    else if(ui->pushButton_divide->isChecked())
    {
        labelnumber = firstNum / secondNum;
        ui->pushButton_divide->setChecked(false);
        symbol = " / ";
    }
    // Setting the equation label
    ui->label_9->setText(QString::number(firstNum,'g',15) + symbol + QString::number(secondNum,'g',15));
    input = QString::number(labelnumber,'g',15);
    ui->label_10->setText(input);

    user_is_typing_secondNumber=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    //double labelnumber;
    //QString input;

    firstNum = ui->label_10->text().toDouble();
    button->setChecked(true);

}


//*****Gestion Dons*****


void MainWindow::on_pb_ajouter_clicked()
{

   int id=ui->le_cin->text().toInt();
   int montant=ui->le_montant->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
//QString  role=ui->le_role->text();
QString produit=ui->le_produit->text();
QString role =ui->combo->currentText();
QDate dateD =ui->le_date->date();
Historique h;
          h.save("id:"+ui->le_cin->text(),"montant:"+ui->le_montant->text()," role:"+ui->combo->currentText(),"prenom :"+ui->le_prenom->text(),"nom :"+ui->le_nom->text(),"produit :"+ui->le_produit->text(),"dateD :"+ui->le_date->text());


   Dons D( id, nom, prenom,role ,produit , montant , dateD);

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


int id=ui->le_cin_2->text().toInt();
QString prenom=ui->le_prenom_2->text();
QString nom=ui->le_nom_2->text();
//QString role=ui->le_nom_2->text();
QString role=ui->combo_modif->currentText();
int montant=ui->le_montant_2->text().toInt();
QString produit=ui->le_produit_2->text();
QDate dateD=ui->le_date_2->date();



   Dons D(  id, nom, prenom, role ,produit , montant,dateD);
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
            ui->le_prenom_2->setText(qry.value(1).toString());
          ui->le_nom_2->setText(qry.value(2).toString());



            ui->combo_modif->setCurrentText(qry.value(3).toString());
             ui->le_montant_2->setText(qry.value(5).toString());
              ui->le_produit_2->setText(qry.value(4).toString());
                ui->le_date_2->setDate(qry.value(6).toDate());

        }
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("ERROR" "click cancel to exit."),QMessageBox::Cancel);
    }
}







double MainWindow ::getlineEditNum()
{
    num1=ui->num1->text().toDouble();
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

//To use
// you dont need that just makes my DB createConnection();


void MainWindow::on_pushButton_11_clicked()
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


void MainWindow::on_pushButton_10_clicked()
{
     QFile file("C:/Users/soyre/Documents/integration_finale/Historiques.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "file not found ";
        qCritical() << file.errorString();

    }
    QTextStream in(&file);
    ui->textBrowser_2->setText(in.readAll());
}

void MainWindow::on_pushButton_12_clicked()
{
    QString prenom=ui->recherche_2->text();

    ui->tab_recherche->setModel(D.recherche_prenom(prenom)) ;

}

void MainWindow::on_acc_clicked()
{
     INO.write_to_arduino(("1"));
}

void MainWindow::on_ref_clicked()
{
     INO.write_to_arduino(("0"));
}

void MainWindow::on_verif_clicked()
{
    int nbr= ui->nbr->text().toInt();
     if(nbr>20)
      {
           INO.write_to_arduino(("1"));
      }
     else if(nbr<=20)
      {
           INO.write_to_arduino(("0"));
       }
}

//*****Gestion Activités*****


void MainWindow::on_pb_ajout_clicked()
{
    int idA=ui->le_id->text().toInt();
    QString nomA=ui->le_nom_3->text();
    QString dateA=ui->le_date_3->text();
    QString description=ui->le_description->text();
    int statu=ui->le_statu->text().toInt();

     Activite A(idA,nomA,dateA,description,statu);

     bool test=A.ajouter();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("Ajout avec succes");
     else
       msgbox.setText("Echec d'ajout");
       msgbox.exec();
     ui->tab_act->setModel(A.afficher());
}

void MainWindow::on_pb_supp_clicked() //suppression
{
  Activite A1 ;
  A1.setidA(ui->le_sup->text().toInt());
    bool test=A1.supprimer(A1.getidA());
    QMessageBox msgBox;
    if (test)
        msgBox.setText("Suppression avec succés");
        else
     msgBox.setText("Echec de suppression");
     msgBox.exec();

}


void MainWindow::on_on_pb_modifier_clicked_clicked()
{
    int idA=ui->le_modifid->text().toInt();
    QString nomA=ui->le_modifnom->text();
     QString dateA=ui->le_modifDate->text();
      QString descritption=ui->le_descriptionModif->text();
       int statu=ui->le_statuModif->text().toInt();


     Activite A(idA,nomA,dateA,descritption,statu);

     bool test=A.modifier();
     QMessageBox msgbox;
     if(test)
        msgbox.setText("Modification avec succés");
     else
        msgbox.setText("Echec de modification");
     msgbox.exec();
}

void MainWindow::on_pb_affichierExecuter_clicked()
{
    ui->tab_act->setModel(A.afficher());
}


void MainWindow::on_tab_act_activated(const QModelIndex &index)
{
    QString val=ui->tab_act->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from ACTIVITE where idA='"+val+"' or nomA='"+val+"' or dateA='"+val+"' or description='"+val+"' or statu='"+val+"' " );
        if(qry.exec())
        {
        while(qry.next())
        {
            ui->le_modifid->setText((qry.value(0).toString()));
            ui->le_modifnom->setText(qry.value(1).toString());
            ui->le_modifDate->setText(qry.value(2).toString());
            ui->le_descriptionModif->setText(qry.value(3).toString());
            ui->le_statuModif->setText(qry.value(4).toString());

         }
        }
}
//LES METIERS

//RECHERCHE par nom
void MainWindow::on_rechercheN_clicked()
{
        QString nomA=ui->le_recherche->text();
        ui->tab_act->setModel(A.recherche(nomA)) ;
}

//FILTRAGE SELON STATU+NOTIFICATION
void MainWindow::on_encours_clicked()
{
     ui->tab_act->setModel(A.StatuEncours());
}

void MainWindow::on_done_clicked()
{
     ui->tab_act->setModel(A.StatuDone());
}

void MainWindow::on_todo_clicked()
{
     ui->tab_act->setModel(A.StatuTodo());
}

//HISTORIQUE
void MainWindow::on_ajoutHis_clicked()
{
    historiquec h;
    QString textajouter;

            int idA = ui->le_id->text().toInt();
            QString nomA= ui->le_nom_3->text();
            QString dateA= ui->le_date_3->text();
             QString description= ui->le_description->text();
             int statu = ui->le_statu->text().toInt();

        int x=0;

          if (idA==0 )
            {
                qDebug () <<"Problem d'ajout dans la base!! ";
                      QMessageBox::critical(this,"Enregistrer","Verifier l'identifiant!");
                      x++;

            }

                if (nomA=="" )
                {
                    qDebug () <<"Problem d'ajout dans la base!!";
                          QMessageBox::critical(this,"Enregistrer","Verifier le nom!");
                          x++;

                }

                 if (dateA=="" )
                 {
                     qDebug () <<"Problem d'ajout dans la base!!";
                           QMessageBox::critical(this,"Enregistrer","verifier la date");
                           x++;

                 }
                 if (description=="" )
                 {
                     qDebug () <<"Problem d'ajout dans la base!!";
                           QMessageBox::critical(this,"Enregistrer","verifier la description!");
                           x++;

                 }
              if ((statu!=0) && (statu!=1) && (statu!=2))
                 {
                     qDebug () <<"Problem d'ajout dans la base!!";
                    QMessageBox::critical(this,"Enregistrer","verifier le statu!");
                     x++;

                  }


        if(x==0)
        {
           Activite A(idA,nomA,dateA,description,statu);
          bool test=A.ajouter();
          if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("Ajouter une activité "),
                          QObject::tr("Activité Ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
         else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une activité"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

            }

        textajouter="L'ajout dans la base de donnees ACTIVITE a ete effectuee avec succees";
        h.write(textajouter);

    }

void MainWindow::on_supprimerHisto_clicked()
{
        historiquec h;
        int verif=0;

        int idA= ui->le_sup->text().toInt();

        qDebug()<< idA ;
       // qDebug()<< idA ;
        verif= QMessageBox::question( this, "Confimation de la Suppression", "Question", QMessageBox::No | QMessageBox::Yes  );

        qDebug()<< verif ;

        if(verif==16384)
        {

    bool test=A.supprimer(idA);
    if(test)
    {ui->tab_act->setModel(A.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une activité"),
                    QObject::tr("Activité supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une activité"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        }

     else if(verif==65536)
        {

            QMessageBox::information(nullptr, QObject::tr("Suppression annulée"),
                        QObject::tr("Suppression annulée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }
        QString textajouter;
        QModelIndex  modele =ui->tab_act->currentIndex().sibling(ui->tab_act->currentIndex().row(),0);
        QString value=modele.data().toString();
          qDebug () << value;
        textajouter="La Suppresion dans la base de donnees ACTIVITE a ete effectuee avec succees";
        h.write(textajouter);
    }


void MainWindow::on_modifierHisto_clicked()
{
        historiquec h;
        QString textajouter;

        int idA= ui->le_modifid->text().toInt();
        QString nomA = ui->le_modifnom->text();
        QString dateA = ui->le_modifDate->text();
         QString description = ui->le_descriptionModif->text();
          int statu = ui->le_statuModif->text().toInt();

       Activite A(idA,nomA,dateA,description,statu);

        bool test=A.modifier();
      if(test)
    {
         ui->tab_act->setModel(A.afficher());
         ui->tab_act->setModel(A.afficher());
         ui->tab_act->setModel(A.afficher());
         ui->tab_act->setModel(A.afficher());
         ui->tab_act->setModel(A.afficher());

       // MainWindow::makePlot();
    QMessageBox::information(nullptr, QObject::tr("Modifier une activité"),
                      QObject::tr("Activité Modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier une activité"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      textajouter="La modification dans la base de donnees ACTIVITE a ete effectuee avec succees";
       h.write(textajouter);

    }

//Annuler l'ajout , suppression , modification
void MainWindow::on_annuler_suppression_clicked()
{
    ui->le_sup->clear();
}

void MainWindow::on_Annuler_Modification_clicked()
{
    ui->le_modifid->clear();
    ui->le_modifnom->clear();
    ui->le_modifDate->clear();
    ui->le_descriptionModif->clear();
    ui->le_statuModif->clear();

}

void MainWindow::on_Annuler_Ajouter_clicked()
{
    ui->le_id->clear();
    ui->le_nom_3->clear();
    ui->le_date_3->clear();
    ui->le_description->clear();
    ui->le_statu->clear();

}


//TRI PAR NOM
void MainWindow::on_TRI_PAR_NOM_CROISSANT_clicked()
{
     ui->tab_act->setModel(A.TriParNomC());
}

void MainWindow::on_TRI_PAR_NOM_DECROISSANT_clicked()
{
     ui->tab_act->setModel(A.TriParNomD());
}

//TRI PAR ID
void MainWindow::on_TRI_ID_CROISSANT_clicked()
{
     ui->tab_act->setModel(A.TriParIdC());
}

void MainWindow::on_TRI_ID_DECROISSANT_clicked()
{
     ui->tab_act->setModel(A.TriParIdD());
}
//TRI PAR DATE
void MainWindow::on_TRI_DATE_CROISSANT_clicked()
{
    ui->tab_act->setModel(A.TriParDateC());
}


void MainWindow::on_TRI_DATE_DECROISSANTE_clicked()
{
     ui->tab_act->setModel(A.TriParDateD());
}

//IMPRESSION
void MainWindow::on_IMPRIMER_clicked()
{
    QModelIndex index=ui->tab_act->currentIndex();
    QString  info = index.data(Qt::DisplayRole).toString();
   QSqlQuery view;
   QPlainTextEdit text;
    Activite A;

   QString idA,nomA,dateA,description,statu,cinE;

          view=A.editview(info);
          //view.next();
          while ( view.next()) {

  idA=view.value(0).toString();
  nomA=view.value(1).toString();
  dateA=view.value(2).toString();
  description=view.value(3).toString();
  statu=view.value(4).toString();
  cinE=view.value(5).toString();

          text.appendPlainText("");
          text.appendPlainText("");
          text.appendPlainText("ID: "+idA+"");
          text.appendPlainText("NOM: "+nomA+"");
          text.appendPlainText("DATE: "+dateA+"");
          text.appendPlainText("DESCRIPTION: "+description+"");
          text.appendPlainText("STATU: "+statu+"");
         text.appendPlainText("CinEmploye: "+cinE+"");

  }
              QPrinter p;
              p.setPrinterName("Print");
              QPrintDialog dlg(&p,this);
              if (dlg.exec() == QDialog::Rejected)
              {
                  return;
              }
              text.print(&p);


}

//CHAT
void MainWindow::on_chat_clicked()
{
    ch =new chat(this);
    ch->show();
}
//RECHERCHE PAR STATU
void MainWindow::on_rechercheS_clicked()
{
   QString statu=ui->le_recherche->text();
    ui->tab_act->setModel(A.rechercheS(statu)) ;
}
//RECHERCHE PAR ID
void MainWindow::on_rechercheI_clicked()
{
   QString idA=ui->le_recherche->text();
   ui->tab_act->setModel(A.rechercheI(idA)) ;
}
//CHAT2
void MainWindow::on_chat2_clicked()
{
    chh =new chat2(this);
    chh->show();
}



//*****Gestion Handicapés******



/*********************************************** ajouter *******************************************************/

void MainWindow::on_pb_ajouter_1_clicked()
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

void MainWindow::on_pb_supprimer1_clicked()
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
void MainWindow::on_rendez_vous_clicked()
{
   QString rdvv=ui->rdvv->date().toString("dd.MM.yyyy");
int id=ui->comboBox_2->currentText().toUInt();

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


void MainWindow::on_rdv_today_clicked()
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



//*****Gestion Employé*****



//---------------------------Arduinoooo-------------------------------------------------
void MainWindow::update_label()
{
    data=ARD.read_from_arduino();

    if(data=="1")

        ui->label_42->setText("Nembre ATTEIN"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_42->setText("Nembre NON ATTEIN");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}





//--------------------------------------------------------------------------------------------------------





void MainWindow::on_pb_ajouter_2_clicked()
{   int cin=ui->le_cin_3->text().toInt();

    int telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString jours_de_travail=ui->les_jours->text();
    QString nom=ui->le_nom_4->text();
    QString prenom=ui->le_prenom_3->text();
    QString fonction=ui->le_fonct->text();

   Employe E(cin,nom,prenom,telephone,jours_de_travail,salaire,fonction);
bool test=E.ajouter();
if(test)
 { ui->table_E->setModel(E.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("add successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("add failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);



}
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    days=days+date.toString()+"|";
    ui->les_jours->setText(days);

}
void MainWindow::on_modifier_2_clicked()
{
    int cin=ui->modifcin->text().toUInt();
    int tel=ui->modiftel->text().toUInt();
    QString jours=ui->modifj->text();
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

void MainWindow::on_pb_supprimer_2_clicked()
{
    int cin=ui->modifcin->text().toInt();
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




void MainWindow::on_sms_clicked()
{/*
    QDesktopServices::openUrl(QUrl("https://www.tunisiesms.tn/client/Api/Api.aspx?fct=sms&key=8AyZ/Lm/Xo/-/XuoYDrY7SAH24WFS9LNNnNdBX5rq4LKdwxHF9uRijDREh9y5//v7fSG59iW9vUhwpNdmQgfkfm8l/-/7YM9IRM4&mobile=21620585505&sms=Bonjour vous avez une reunion aujourd'hui date 05/04/2021&sender=TunSMS Test&date=04/04/2022&heure=14:44"));
*/}

void MainWindow::on_pb_go_clicked()
{
    QString nom = ui->input_recherche_2->text();
    if(nom=="")
    {
        ui->table_rech_2->setModel(E.afficher());
    }
    else
    {
        if( ui->rfonction->isChecked())
        {
            ui->table_rech_2->setModel(E.recherche_fonction(nom));
        }
        if( ui->rnom->isChecked())
        {
            ui->table_rech_2->setModel(E.recherche_nom(nom));
        }
        if( ui->rprenom->isChecked())
        {
            ui->table_rech_2->setModel(E.recherche_prenom(nom));
        }
    }
}
void MainWindow::on_rprenom_stateChanged(int arg1)
{
    if(ui->rprenom->isChecked())
    {
    ui->rfonction->setDisabled(true);
    ui->rnom->setDisabled(true);
    }
    else
    {
        ui->rfonction->setDisabled(false);
        ui->rnom->setDisabled(false);

    }
}


void MainWindow::on_rnom_stateChanged(int arg1)
{
    if(ui->rnom->isChecked())
    {
    ui->rfonction->setDisabled(true);
    ui->rprenom->setDisabled(true);
    }
    else
    {
        ui->rfonction->setDisabled(false);
        ui->rprenom->setDisabled(false);

    }
}

void MainWindow::on_rfonction_stateChanged(int arg1)
{
    if(ui->rfonction->isChecked())
    {
    ui->rnom->setDisabled(true);
    ui->rprenom->setDisabled(true);
    }
    else
    {
        ui->rnom->setDisabled(false);
        ui->rprenom->setDisabled(false);

    }
}
//---------------------pdf----------------------------
void MainWindow::on_pdf_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                       const int rowCount = ui->table_E->model()->rowCount();
                       const int columnCount = ui->table_E->model()->columnCount();
                      out <<  "<html>\n"
                      "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("strTitle")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"

                                      //     "<align='right'> " << datefich << "</align>"
                                       "<center> <H1>Liste des employes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                   // headers
                                   out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                   out<<"<cellspacing=10 cellpadding=3>";
                                   for (int column = 0; column < columnCount; column++)
                                       if (!ui->table_E->isColumnHidden(column))
                                           out << QString("<th>%1</th>").arg(ui->table_E->model()->headerData(column, Qt::Horizontal).toString());
                                   out << "</tr></thead>\n";

                                   // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->table_E->isColumnHidden(column)) {
                                               QString data = ui->table_E->model()->data(ui->table_E->model()->index(row, column)).toString().simplified();
                                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                           }
                                       }
                                       out << "</tr>\n";
                                   }
                                   out <<  "</table> </center>\n"
                                       "</body>\n"
                                       "</html>\n";

                             QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                               if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                              QPrinter printer (QPrinter::PrinterResolution);
                               printer.setOutputFormat(QPrinter::PdfFormat);
                              printer.setPaperSize(QPrinter::A4);
                             printer.setOutputFileName(fileName);

                              QTextDocument doc;
                               doc.setHtml(strStream);
                               doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                               doc.print(&printer);
}
//--------imprimer------------------------

void MainWindow::on_pb_imprimer_clicked()
{
    QPlainTextEdit text;
    QString cin,telephone,nom,prenom,fonction,jours_de_travails,salaire;
    cin=ui->modifcin->text();
    telephone=ui->modiftel->text();
    nom=ui->modifnom->text();
    prenom=ui->modifpr->text();
    fonction=ui->modiff->text();
     jours_de_travails=ui->modifj->text();
      salaire=ui->modifs->text();



text.appendPlainText("CIN: "+cin+"");
text.appendPlainText("telephone: "+telephone+"");
text.appendPlainText("nom: "+nom+"");
text.appendPlainText("prenom: "+prenom+"");
text.appendPlainText("fonction: "+fonction+"");
text.appendPlainText("jours: "+jours_de_travails+"");
text.appendPlainText("fonction: "+salaire+"");

   QPrinter printer ;
   printer.setPrinterName("Print");
   QPrintDialog dlg(&printer,this);
   if (dlg.exec() == QDialog::Rejected)
   {
       return;
   }
   text.print(&printer);


}
//----------triii nom-------
void MainWindow::on_tri_clicked()
{
      ui->table_E->setModel(E.afficher_tri_nom());
}
//-------- tri prenom-------


void MainWindow::on_tri_prenom_clicked()
{
     ui->table_E->setModel(E.afficher_tri_prenom());
}
//-------- tri prenom-------


void MainWindow::on_tri_fonction_clicked()
{
     ui->table_E->setModel(E.afficher_tri_fonction());
}



//-----------Arduinoooo--------------------------------------------------------------------------------


void MainWindow::on_on_button_clicked()
{
      ARD.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_off_button_clicked()
{
     ARD.write_to_arduino("0");  //envoyer 0 à arduino
}



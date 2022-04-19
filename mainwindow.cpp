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
QTimer *timer = new QTimer();

double firstNum;
bool user_is_typing_secondNumber=false;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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
            break;
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
       connect(timer,SIGNAL(timeout()),this,SLOT(updatee_label()));
       timer->start(100);
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

}

MainWindow::~MainWindow()
{
    delete ui;
}


//*****CRUD*****


void MainWindow::on_ajouter_clicked()
{

        int id_depenses=ui->lineEdit_id_depenses->text().toInt();
        QDate date_depenses=ui->lineEdit_date_depenses->date();
        QString type_depenses=ui->lineEdit_type_depenses->currentText();
        int montant=ui->lineEdit_montant->text().toInt();
        Historique h;
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




//*****Clear*****


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


//*****Recherche Avancée*****


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


//*****Remplir les variables du tableau*****


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


//*****Stats*****


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

//*****PDF****

void MainWindow::on_pushButton_PDF_clicked()
{
    depenses D;
    D.creerpdf();
}

//*****Historique*****


void MainWindow::on_historique_clicked()
    {

    QFile file("C:/Users/soyre/Documents/Project/his.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "file not found ";
        qCritical() << file.errorString();

    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());

    }

//*****Calculatrice*****

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

//*****

void MainWindow::updatee_label()
{
    data=A.read_from_arduino();
qDebug()<< data;
    if(data=="1"){
        A.write_to_arduino("1"); //envoyer 1 à arduino
    // alors afficher msg
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("ok card.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

    if (data=="2"){
       A.write_to_arduino("0");  //envoyer 0 à arduino
       QMessageBox::information(nullptr, QObject::tr("no"),
                                       QObject::tr("no.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
     //alors afficher msg

}
}


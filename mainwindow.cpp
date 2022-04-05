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
QString days="";
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->table_E->setModel(E.afficher());
        ui->le_cin->setValidator(new QIntValidator(0,99999999,this));
                ui->le_tel->setValidator(new QIntValidator(0,99999999,this));
               // ui->les_jours->setValidator(new QIntValidator(0,7,this));
                 ui->le_salaire->setValidator(new QIntValidator(0,9999999,this));
                QRegExp rx("^[A-Z][a-z]{0,10}$");
                ui->le_nom->setValidator(new QRegExpValidator(rx, this));

                ui->le_prenom->setValidator(new QRegExpValidator(rx, this));
                ui->le_fonct->setValidator(new QRegExpValidator(rx, this));
         ui->modifnom->setValidator(new QRegExpValidator(rx, this));
          ui->modifpr->setValidator(new QRegExpValidator(rx, this));
             ui->modifs->setValidator(new QIntValidator(0,9999999,this));

           ui->modifcin->setValidator(new QIntValidator(0,99999999,this));
           ui->modiftel->setValidator(new QIntValidator(0,99999999,this));
          // ui->modifj->setValidator(new QIntValidator(0,7,this));
    }



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{   int cin=ui->le_cin->text().toInt();

    int telephone=ui->le_tel->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString jours_de_travail=ui->les_jours->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
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
void MainWindow::on_modifier_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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




void MainWindow::on_pushButton_6_clicked()
{
   // QDesktopServices::openUrl(QUrl("https://www.tunisiesms.tn/client/Api/Api.aspx?fct=sms&key=8AyZ/Lm/Xo/-/XuoYDrY7SAH24WFS9LNNnNdBX5rq4LKdwxHF9uRijDREh9y5//v7fSG59iW9vUhwpNdmQgfkfm8l/-/7YM9IRM4&mobile=21620585505&sms=test qt&sender=TunSMS Test&date=04/04/2022&heure=14:44"));
}

void MainWindow::on_pb_go_clicked()
{
    QString nom = ui->input_recherche->text();
    if(nom=="")
    {
        ui->table_rech->setModel(E.afficher());
    }
    else
    {
        if( ui->rfonction->isChecked())
        {
            ui->table_rech->setModel(E.recherche_fonction(nom));
        }
        if( ui->rnom->isChecked())
        {
            ui->table_rech->setModel(E.recherche_nom(nom));
        }
        if( ui->rprenom->isChecked())
        {
            ui->table_rech->setModel(E.recherche_prenom(nom));
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

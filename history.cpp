#include "history.h"
#include<QMessageBox>

History::History()
{
tmp="";
}
void History::save(QString id_depenses ,QString date_depenses ,QString type_depenses ,QString montant)
{    QFile file ("C:/Users/soyre/Documents/integration_finale/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id_depenses+"\n"+date_depenses << "\n" +type_depenses << "\n" +montant << "\n""------------------------------------------------" << "\n" ;


}

QString History::load()
{   tmp="";
    QFile file("C:/Users/soyre/Documents/integration_finale/his.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         qDebug()<<"erreur";
      tmp="";

    QTextStream in(&file);

  while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }

   return tmp;
}


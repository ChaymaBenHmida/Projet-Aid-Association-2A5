#include "historique.h"
#include<QMessageBox>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString id,QString nom,QString prenom,QString role ,QString produit ,QString montant)
{    QFile file ("C:/Users/user/Documents/projetQT/Historiques.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id+"\n"+nom << "\n" +prenom << "\n" +role << "\n" +montant <<"\n" +produit <<"\n";


}

QString Historique::load()
{   tmp="";
    QFile file("C:/Users/user/Documents/projetQT/Historiques.txt");
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

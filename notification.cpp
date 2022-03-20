#include "handicape.h"
#include<QObject>
#include<QSqlQuery>
#include <QtDebug>

void handicape::notifications_supprimer()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des handicapes ","handicape Supprimée",QSystemTrayIcon::Information,15000);
}

void handicape::notifications_ajouter()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des handicapes ","handicape ajoutée ",QSystemTrayIcon::Information,15000);
}

void handicape::notifications_modifier()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des handicapes ","handicape modifiée ",QSystemTrayIcon::Information,15000);
}

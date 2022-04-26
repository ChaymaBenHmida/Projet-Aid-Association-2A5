#include "notification.h"

void notification::notification_act()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("notification.jpg"));

    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Notification","Attention!! Activité(s) Passée(s) !",QSystemTrayIcon::Information,15000);

}

#ifndef DIALOG_H
#define DIALOG_H
#include "activite.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setclient(Client c);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

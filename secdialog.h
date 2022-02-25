#ifndef SECDIALOG_H
#define SECDIALOG_H
#include "handicape.h"
#include <QDialog>

namespace Ui {
class secdialog;
}

class secdialog : public QDialog
{
    Q_OBJECT

public:
    explicit secdialog(QWidget *parent = nullptr);
    ~secdialog();

private slots:
    void on_pb_modifier_clicked();

private:
    Ui::secdialog *ui;
    handicape h;
};

#endif // SECDIALOG_H

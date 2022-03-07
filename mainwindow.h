#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_modifier_clicked();

    void on_table_E_activated(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
    int me;
};

#endif // MAINWINDOW_H

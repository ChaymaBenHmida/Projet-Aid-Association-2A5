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
    void on_pb_go_clicked();

    void on_rnom_stateChanged(int arg1);

    void on_rprenom_stateChanged(int arg1);

    void on_rfonction_stateChanged(int arg1);
     void on_pdf_clicked();

    void on_calendarWidget_clicked(const QDate &date);


    void on_pushButton_6_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_imprimer_clicked();


    void on_tri_clicked();

    void on_tri_prenom_clicked();
    void on_tri_fonction_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
    int me;
};

#endif // MAINWINDOW_H

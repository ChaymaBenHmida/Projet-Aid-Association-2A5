#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dons.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    double num1=0,num2=0,result=0;
   double getlineEditNum();
   void writelabelResult( double tempResult);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_tab_dons_activated(const QModelIndex &index);
     void on_tab_recherche_activated(const QModelIndex &index);


    void on_pb_modifier_clicked();

    //void on_Button0_pressed();

  ;

    void on_addbutton_clicked();

    void on_Minusvutton_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_imprimer_clicked();

    void on_pushButton_5_clicked();

    void on_recherche_role_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dons D;
};
#endif // MAINWINDOW_H

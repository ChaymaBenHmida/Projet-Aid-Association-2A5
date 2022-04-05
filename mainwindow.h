#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "handicape.h"
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

    void on_pb_supprimer_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_table_handicape_activated(const QModelIndex &index);

    void on_pb_modifier_2_clicked();

    void on_pb_clear_clicked();

    void on_pushButton_clicked();

    void on_rech_prenom_stateChanged(int arg1);

    void on_rech_nom_stateChanged(int arg1);

    void on_rech_age_stateChanged(int arg1);

    void on_pb_print_clicked();

    void on_pb_imprimer_handicape_clicked();

    void on_pb_excel_clicked();

    void on_pb_img_clicked();

    void on_pb_modifier_img_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_table_rdv_activated(const QModelIndex &index);

    void on_datee_activated(const QModelIndex &index);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
handicape h;
};
#endif // MAINWINDOW_H

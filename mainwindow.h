#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include "arduino.h"
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

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino





    void on_on_button_clicked();

    void on_off_button_clicked();

    void on_label_23_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    Employe E;
    int me;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H

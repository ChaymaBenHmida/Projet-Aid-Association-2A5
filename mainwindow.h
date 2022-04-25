#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//*****include karim*****
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QStaticStringData>
#include <QTextEdit>
#include <QtCharts>
#include <QChartView>
#include <QSqlQuery>
#include <QLineSeries>
#include "depenses.h"
#include "history.h"

//*****include tasnim*****

#include "dons.h"
#include"arduino1.h"

//*****include chayma*****

#include <QWidget>
#include <QMainWindow>
#include<QFile>

#include"activite.h"
#include"historiquec.h"
#include "chat.h"
#include<QTcpSocket>
#include"chat2.h"

//*****include maryem******

#include "handicape.h"
#include "arduino.h"
#include <QMainWindow>

//*****include chahrazed******

#include "employes.h"
#include "arduino.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class QSystemTrayIcon; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    depenses tmp;


public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //*****public tasnim*****

        double num1=0,num2=0,result=0;
        double getlineEditNum();
        void writelabelResult( double tempResult);

    QSortFilterProxyModel *proxy;
    void show_table();
    void fill_form(QString selected );
    void clear_form( );

private slots:

//*****Menu*****

    void on_Acceuil_clicked();

    void on_Employes_clicked();

    void on_Handicapes_clicked();

    void on_Activites_clicked();

    void on_Dons_clicked();

    void on_Depenses_clicked();

    void on_Quitter_clicked();

//*****private slots karim*****

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_clear_clicked();

    void on_stats_clicked();

    void on_pushButton_PDF_clicked();

    void on_history_clicked();

    void digit_pressed();

    void on_pushButton_dot_released();

    void unary_operation_pressed();

    void on_pushButton_clear_released();

    void on_pushButton_equals_released();

    void binary_operation_pressed();

//*****private slots tasnim*****

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tab_dons_activated(const QModelIndex &index);

    void on_tab_recherche_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_addbutton_clicked();

    void on_Minusvutton_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_imprimer_clicked();

    void on_pushButton_11_clicked();

    void on_recherche_role_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_acc_clicked();

    void on_ref_clicked();

    void on_verif_clicked();

//*****private slots chayma*****

    void on_pb_supp_clicked(); //suppression

    void on_pb_ajout_clicked();

    void on_on_pb_modifier_clicked_clicked();

    void on_pb_affichierExecuter_clicked();

    void on_rechercheN_clicked();

    void on_tab_act_activated(const QModelIndex &index);

    void on_encours_clicked();

    void on_done_clicked();

    void on_todo_clicked();

    void on_ajoutHis_clicked();

    void on_supprimerHisto_clicked();

    void on_modifierHisto_clicked();

    void on_annuler_suppression_clicked();

    void on_Annuler_Modification_clicked();

    void on_Annuler_Ajouter_clicked();

    void on_TRI_PAR_NOM_CROISSANT_clicked();

    void on_TRI_PAR_NOM_DECROISSANT_clicked();

    void on_TRI_ID_CROISSANT_clicked();

    void on_TRI_ID_DECROISSANT_clicked();

    void on_TRI_DATE_CROISSANT_clicked();

    void on_TRI_DATE_DECROISSANTE_clicked();

    void on_IMPRIMER_clicked();

    void on_chat_clicked();

    void on_rechercheS_clicked();

    void on_rechercheI_clicked();

    void on_chat2_clicked();

//*****private slots maryem******

    void on_pb_ajouter_1_clicked();

    void on_pb_supprimer1_clicked();

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

    void on_rendez_vous_clicked();

    void on_datee_activated(const QModelIndex &index);

    void on_comboBox_activated(const QString &arg1);

    void on_rdv_today_clicked();

//*****private slots chahrazed******

    void on_pb_ajouter_2_clicked();

    void on_modifier_2_clicked();

    void on_table_E_activated(const QModelIndex &index);

    void on_pb_go_clicked();

    void on_rnom_stateChanged(int arg1);

    void on_rprenom_stateChanged(int arg1);

    void on_rfonction_stateChanged(int arg1);

     void on_pdf_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_sms_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_imprimer_clicked();

    void on_tri_clicked();

    void on_tri_prenom_clicked();

    void on_tri_fonction_clicked();

    void update_label();

    void on_on_button_clicked();

    void on_off_button_clicked();




private:

//*****private karim*****

    Ui::MainWindow *ui;
    QSystemTrayIcon *mSystemTrayIcon;
    depenses Stmp;
    int sel_col=-1;
    QString selected="";
    History H;

//*****private tasnim*****

    Dons D;


//*****private chayma*****

    Activite A; //constance de type activite
    chat *ch;
    chat2 *chh;

//*****private maryem

    handicape h;
    Arduino INO;


//*****private chahrazed

    Employe E;
    int me;
    QByteArray data; // variable contenant les données reçue
    Arduino ARD; // objet temporaire
};
#endif // MAINWINDOW_H

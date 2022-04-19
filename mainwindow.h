#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "depenses.h"
#include "history.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QStaticStringData>
#include<QTextEdit>
#include <QtCharts>
#include <QChartView>
#include <QSqlQuery>
#include <QLineSeries>
#include "arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class QSystemTrayIcon;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    depenses tmp;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSortFilterProxyModel *proxy;
    void show_table();
    void fill_form(QString selected );
    void clear_form( );

private slots:

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

    void on_historique_clicked();

        void digit_pressed();

        void on_pushButton_dot_released();
        void unary_operation_pressed();
        void on_pushButton_clear_released();
        void on_pushButton_equals_released();
        void binary_operation_pressed();



            void updatee_label();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *mSystemTrayIcon;
    depenses Stmp;
    int sel_col=-1;
    QString selected="";
    Historique H;
    Arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H

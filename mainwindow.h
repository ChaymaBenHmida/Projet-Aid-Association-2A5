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

private:
    Ui::MainWindow *ui;
handicape h;
};
#endif // MAINWINDOW_H

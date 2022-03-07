#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"activite.h"

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

    void on_pushButton_7_clicked(); //suppression

    void on_pb_ajout_clicked();

    void on_on_pb_modifier_clicked_clicked();

    void on_pb_affichierExecuter_clicked();

    void on_recherche_clicked();

private:
    Ui::MainWindow *ui;
    Activite A;
};
#endif // MAINWINDOW_H

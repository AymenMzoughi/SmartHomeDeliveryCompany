#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "admin.h"
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
    void on_Commande_clicked();


    void on_pushButtonemployees_clicked();

    void on_pushButtonclients_clicked();

    void on_pushButtonstock_clicked();

    void on_pushButtonsav_clicked();

    void on_pageacc_clicked();

    void on_pb_clear_clicked();

    void on_pb_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

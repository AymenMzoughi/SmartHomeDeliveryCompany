#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "conge.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

QMediaPlayer* player= new QMediaPlayer;

private slots:
    void on_pb_ajouter_clicked();

    void on_chercher_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_pb_ajouterc_clicked();

    void on_pb_modifierc_clicked();

    void on_pb_supprimerc_clicked();

    void on_recherchec_clicked();

    void on_affichage_clicked();

    void on_TrierC_clicked();

    void on_affichagec_clicked();

    bool controlenum(int test);
    bool controleVide(QString test);
    bool controleEmail(QString test);

    void on_pushButton_27_clicked();

private:
    Ui::MainWindow *ui;
    Employe E1;
    Conge C1;
};
#endif // MAINWINDOW_H

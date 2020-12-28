#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "admin.h"
#include <QMainWindow>
#include"employe.h"
#include"conge.h"
#include"commande.h"
#include"commande_colis.h"
#include"vehicule.h"
#include"statistique_veh.h"
#include"arduino.h"
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

    void on_pb_ajouter_2_clicked();

    void on_pb_modifierc_2_clicked();

    void on_pb_supprimerc_2_clicked();

    void on_affichagec_2_clicked();

    void on_recherchec_2_clicked();

    void on_chercher_3_clicked();

    void on_affichage_2_clicked();

    void on_tabemp_2_activated(const QModelIndex &index);

    void on_pb_ajouterc_2_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void on_TrierC_2_clicked();

    void on_tabconge_2_activated(const QModelIndex &index);

    void on_ajouterCommandes_clicked();

    void on_ModifierCommandes_clicked();

    void on_supprimerCommandes_clicked();

    void on_chercher_2Commandes_clicked();

    void on_Affichertout_clicked();

    void on_imprimer_clicked();

    void on_affecter_clicked();

    void on_afficheraffecter_clicked();

    void on_tabcommande_activated(const QModelIndex &index);

    void on_AjouterVehicule_clicked();

    void on_supprimerVehicule_clicked();

    void on_ModifierVehicule_clicked();

    void on_cherchervehicule_clicked();

    void on_Affichertout_2_clicked();

    void on_tabvehicule_activated(const QModelIndex &index);

    void on_statistique_clicked();
    void  update_label();
private:
    Ui::MainWindow *ui;
    Employe E1;
    Conge C1;
    Commande CO1;
    Commande_colis CC;
    Vehicule V1;
    Statistique_veh *s;
    Arduino A;
    QByteArray data;
    int numdesv=0;
    int numplace=30;



};
#endif // MAINWINDOW_H

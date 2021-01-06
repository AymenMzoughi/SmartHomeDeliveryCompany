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
#include "clients.h"
#include "cartefidelite.h"
#include"colis.h"
#include"entrepots.h"
#include <QMediaPlayer>
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
//amine
    bool controlTel(int test);
    bool controlRef(int test);
    bool controlVide(QString test);
    bool controlEmail(QString test);
    bool controlNumero(int test);
    bool controlPoints(int test);
    bool controlCheque(int test);
    void update_rfid();
    //void on_slider_volume_sliderMoved(int position);

    void on_start_clicked();

    void on_pause_clicked();

    //void on_positionChanged(qint64 position);

    void on_tab_cf_activated(const QModelIndex &index);

    void on_tab_client_activated(const QModelIndex &index);


    void on_pb_envoyermail_client_clicked();

    void on_pb_ajout_client_clicked();

    void on_pb_supprimer_client_clicked();

    void on_pb_modif_client_clicked();

    void on_pb_ajout_cf_clicked();

    void on_pb_supp_cf_clicked();

    void on_pb_modifier_cf_clicked();

    void on_comboBox_tri_activated(const QString &arg1);

    void on_comboBox_tri_client_activated(const QString &arg1);

    void on_pb_rech_cf_2_clicked();

    void on_search_pb_clicked();

    void on_pb_rech_cf_3_clicked();

    void on_comboBox_tri_cf_activated(const QString &arg1);

    void on_envoyerCmail_clicked();

    void on_ajouter_colis_clicked();

    void on_tabcolis_activated(const QModelIndex &index);

    void on_modifier_colis_clicked();

    void on_supprimer_colis_clicked();

    void on_chercher_colis_2_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_etr_clicked();

    void on_modifier_entr_clicked();

    void on_supprimer_entro_clicked();

    void on_trier_entr_clicked();

    void on_chercher_entr_clicked();

    void on_tabentrep_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_13_clicked();

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
    int numemp=0;
    int numcolis=0;
    Clients E;
    CarteFidelite CF;
    colis Cl1;
    Entrepots ET1;



};
#endif // MAINWINDOW_H

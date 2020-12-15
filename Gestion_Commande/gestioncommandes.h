#ifndef GESTIONCOMMANDES_H
#define GESTIONCOMMANDES_H

#include <QDialog>
#include"commande.h"
#include"vehicule.h"
#include"commande_colis.h"
#include"arduino.h"
namespace Ui {
class Gestioncommandes;
}

class Gestioncommandes : public QDialog
{
    Q_OBJECT

public:
    explicit Gestioncommandes(QWidget *parent = nullptr);
    ~Gestioncommandes();

private slots:


    void on_ajouterCommandes_clicked();

    void on_supprimerCommandes_clicked();

    void on_ModifierCommandes_clicked();

    void on_chercher_2Commandes_clicked();

    void on_AjouterVehicule_clicked();

    void on_ModifierVehicule_clicked();

    void on_supprimerVehicule_clicked();

    void on_cherchervehicule_clicked();

    void on_affecter_clicked();

    void on_imprimer_clicked();

    void on_Affichertout_clicked();

    void on_Affichertout_2_clicked();

    void on_tabcommande_activated(const QModelIndex &index);

    void on_tabvehicule_activated(const QModelIndex &index);

private:
    Ui::Gestioncommandes *ui;
    Commande C1;
    Vehicule V1;
    Commande_colis CC;
};

#endif // GESTIONCOMMANDES_H

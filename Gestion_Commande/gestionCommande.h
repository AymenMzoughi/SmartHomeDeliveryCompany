#ifndef MAINWIN_H
#define MAINWIN_H

#include <QDialog>
#include"vehiculewin.h"
#include"commandewin.h"
namespace Ui {
class gestionCommande;
}

class  gestionCommande : public QDialog
{
    Q_OBJECT

public:
    explicit  gestionCommande(QWidget *parent = nullptr);
    ~ gestionCommande();

private slots:
    void on_Commande_clicked();

    void on_vehicule_clicked();

private:
    Ui:: gestionCommande *ui;

};

#endif // MAINWIN_H

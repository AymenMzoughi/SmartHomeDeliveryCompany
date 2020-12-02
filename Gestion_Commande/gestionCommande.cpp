#include "gestionCommande.h"


 gestionCommande:: gestionCommande(QWidget *parent) :
    QDialog(parent),
   ui(new Ui::gestionCommande)
{
    ui->setupUi(this);
}

 gestionCommande::~mainwin()
{
    delete ui;
}

void  gestionCommande::on_Commande_clicked()
{
    C.show();
}

void gestionCommande::on_vehicule_clicked()
{
    V.show();
}

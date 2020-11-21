#include "vehiculewin.h"
#include "ui_vehiculewin.h"
#include<vehicule.h>
#include <QMessageBox>
#include<QVBoxLayout>
Vehiculewin::Vehiculewin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vehiculewin)
{
    ui->setupUi(this);
    ui->typecarburant->addItem("gazole");
    ui->typecarburant->addItem("Essence");
    ui->typev->addItem("camion");
    ui->typev->addItem("moto");
    ui->typev->addItem("tricycle");
    ui->typecarburant_2->addItem("gazole");
    ui->typecarburant_2->addItem("Essence");
    ui->typev_2->addItem("camion");
    ui->typev_2->addItem("moto");
    ui->typev_2->addItem("tricycle");
    ui->tabvehicule->setModel(V1.afficher());
}

Vehiculewin::~Vehiculewin()
{
    delete ui;
}

void Vehiculewin::on_Ajouter_clicked()
{
    QString choix1,choix2;
      int idemp=ui->idemp->text().toInt();
    QString  matricule=ui->Matricule->text();
    QString numdechassis=ui->numerochassis->text();
    QString marque=ui->marque->text();
    QDate datec= ui->datecirculation->date();
    QString datecirculation=datec.toString("dd/MM/yy");

  choix1.sprintf("%d",ui->typecarburant->currentIndex());
   QString typecarburant=ui->typecarburant->currentText();
   choix2.sprintf("%d",ui->typev->currentIndex());
    QString typev=ui->typecarburant->currentText();
Vehicule V(matricule,numdechassis,typecarburant,typev,datecirculation,marque,idemp);
     QMessageBox msgBox;
bool test=V.ajouter();
     if(test)
       {  msgBox.setText("Ajout avec succes.");
       ui->tabvehicule->setModel(V1.afficher());
     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }

}

void Vehiculewin::on_supprimer_2_clicked()
{
   Vehicule V;
      V.setmatricule(ui->supprimer->text());
         bool test=V.supprimer(V.getmatricule());
         QMessageBox msgBox;
         if(test)
            { msgBox.setText("Suppression avec succes.");
              ui->tabvehicule->setModel(V1.afficher());

         }
         else
            { msgBox.setText("Echec de suppression");
             msgBox.exec();}
}

void Vehiculewin::on_Modifier_clicked()
{
    QString choix1,choix2;
      int idemp=ui->idemp_2->text().toInt();
    QString  matricule=ui->Matricule_2->text();
    QString numdechassis=ui->numerochassis_2->text();
    QString marque=ui->marque_2->text();
    QDate datec= ui->datecirculation_2->date();
    QString datecirculation=datec.toString("dd/MM/yy");

  choix1.sprintf("%d",ui->typecarburant_2->currentIndex());
   QString typecarburant=ui->typecarburant_2->currentText();
   choix2.sprintf("%d",ui->typev_2->currentIndex());
    QString typev=ui->typecarburant_2->currentText();
Vehicule V(matricule,numdechassis,typecarburant,typev,datecirculation,marque,idemp);
     QMessageBox msgBox;
bool test=V.modifier();
     if(test)
       {  msgBox.setText("modificaton avec succes.");
           ui->tabvehicule->setModel(V1.afficher());
     }
     else
        { msgBox.setText("vehicule n'exite pas ");
         msgBox.exec();
    }
}

#include "gestioncommandes.h"
#include "ui_gestioncommandes.h"
#include"commande.h"
#include"vehicule.h"
#include"commande_colis.h"
#include<QPrinter>
#include<QPainter>
#include<QPdfWriter>
#include <QMessageBox>
#include<QVBoxLayout>
#include<QtDebug>
#include<QFileInfo>
#include<QFileDialog>
#include <QSettings>
#include <QProcess>
#include <QDebug>
#include <QtPrintSupport>
#include<QMediaPlayer>
Gestioncommandes::Gestioncommandes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestioncommandes)
{   ui->setupUi(this);
     ui->le_num->setValidator(new QIntValidator(0, 99999, this));
     ui->Mnum->setValidator(new QIntValidator(0, 99999, this));
      ui->numsupp->setValidator(new QIntValidator(0,99999, this));
//COMBOBOX:commandes
    ui->modepaiment->addItem("cheque");
    ui->modepaiment->addItem("especes");
    ui->modepaiment->addItem("virement");
    ui->Mmodepaiment_2->addItem("cheque");
    ui->Mmodepaiment_2->addItem("especes");
    ui->Mmodepaiment_2->addItem("virement");
    ui->chercher->addItem("modedepaiment");
    ui->chercher->addItem("idclient");
    ui->chercher->addItem("numerocommande");
    ui->comboBoxidclient->setModel(C1.afficher_idclient());
    ui->comboBoxMidclient->setModel(C1.afficher_idclient());
    ui->tabcommande->setModel(C1.afficher());
    ui->idemp->setModel(C1.afficher_idemp());
    ui->idemp_2->setModel(C1.afficher_idemp());
  //COMBOBOX:vehicules
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
  ui->marquev->addItem("Fiat");
  ui->marquev->addItem("Toyota ");
  ui->marquev->addItem("Peugeot");
  ui->marquev->addItem("Citroen");
  ui->marquev->addItem("Renault");
  ui->marquev_2->addItem("Fiat");
  ui->marquev_2->addItem("Toyota ");
  ui->marquev_2->addItem("Peugeot");
  ui->marquev_2->addItem("Citroen");
  ui->marquev_2->addItem("Renault");
  ui->marquev_2->addItem("Vms");
  //COMBOBOX:employe
  ui->comboBoxemp->setModel(V1.affiche_employer());
  ui->comboBoxempM->setModel(V1.affiche_employer());
  //Chercher Vehicule:combobox
  ui->combochercherv->addItem("Matricule");
  ui->combochercherv->addItem("Marque");
  ui->combochercherv->addItem("TypeV");
  ui->combochercherv->addItem("typeCarburant");
  ui->tabvehicule->setModel(V1.afficher());
  //COMBOBOX:affectation
  ui->affectercolis->setModel(CC.afficher_idcolis());
   ui->affecternumcommande->setModel(CC.afficher_idcommande());
}

Gestioncommandes::~Gestioncommandes()
{
    delete ui;
}


//TABLE:Commande
void Gestioncommandes::on_ajouterCommandes_clicked()
{
    QString modepaiment;
    int num=ui->le_num->text().toInt();
    QString numstring=ui->le_num->text();

    QString numverif=ui->le_num->text();
    QString description=ui->description->text();
      int idclient=ui->comboBoxidclient->currentText().toInt();
      QDate date= ui->datedecommande->date();
      QString datedecommande= date.toString("dd/MM/yy");
      modepaiment=ui->modepaiment->currentText();
    float montant=ui->montant->text().toFloat();
    QString idemp=ui->idemp->currentText();
    Commande C(num,description ,datedecommande,modepaiment,montant,idclient,idemp);


     QMessageBox msgBox;

     if(C.verifvidestring(C.getdatecommande())==true&&C.verifint(C.getnum())==true&&C.verifvidestring(C.getdescription())==true&&C.verifvidestring(C.getmodepaiment())==true&&C.verifvidestring(numverif)==true&&C.veriffloat(C.getmontant())==true)
       { bool test=C.ajouter();
         if(test==true)
         {msgBox.setText("Ajout avec succes.");
            ui->tabcommande->setModel(C1.afficher());
            ui->affecternumcommande->setModel(CC.afficher_idcommande());
              msgBox.exec();}
                      else {
                          msgBox.setText("Echec d'ajout");

                      }

         }
        else
        { msgBox.setText("Echec d'ajout");
         }

msgBox.exec();
}

void Gestioncommandes::on_supprimerCommandes_clicked()
{
      QMessageBox msgBox;
      int numtest=ui->numsupp->text().toUInt();
      QString numstring=ui->numsupp->text();
      Commande C;
      C.setnum(numtest);
     bool test1=C.verifierid(C.getnum());
     if(test1==true&&C.verifvidestring(ui->numsupp->text()))
       { C.supprimer(C.getnum());
         msgBox.setText("Suppression avec succes.");

             ui->tabcommande->setModel(C1.afficher());
            CC.updateetat(numtest);

         }
         else
          {msgBox.setText("Echec de suppression");}
             msgBox.exec();
}



void Gestioncommandes::on_ModifierCommandes_clicked()
{
       QMessageBox msgBox;
    QString modepaiment,choix;
    int num=ui->Mnum->text().toInt();
    QString description=ui->Mdescription->text();
      int idclient=ui->comboBoxidclient->currentText().toInt();
      QDate date= ui->Mdate->date();
     QString datedecommande=date.toString("dd/MM/yy");
      modepaiment=ui->Mmodepaiment_2->currentText();
    float montant=ui->MMontant->text().toFloat();
    QString idemp=ui->idemp_2->currentText();
    Commande C(num,description ,datedecommande,modepaiment,montant,idclient,idemp);

if(C.verifvidestring(C.getdatecommande())==true&&C.verifvidestring(C.getdescription())==true&&C.verifvidestring(C.getmodepaiment())==true&&C.veriffloat(C.getmontant())==true&&C.verifierid(num))
 {        C.modifier();
        msgBox.setText("Modification avec succes");
           ui->tabcommande->setModel(C1.afficher());
           }

           else
            { msgBox.setText(" Echec de modification ");
                }
msgBox.exec();
}

void Gestioncommandes::on_chercher_2Commandes_clicked()
{ int choix;
    choix=ui->chercher->currentIndex();
    QString linechercher=ui->lineEditchercher->text();
    ui->tabcommande->setModel(C1.chercher(choix,linechercher));
}
//TABLE:Vehicule
void Gestioncommandes::on_AjouterVehicule_clicked()
{
    QString choix1,choix2;
      int idemp=ui->comboBoxemp->currentText().toInt();
     QString idemps=ui->comboBoxemp->currentText();
    QString  matricule=ui->Matricule->text();
    QString numdechassis=ui->numerochassis->text();
    QString marque=ui->marquev->currentText();
    QDate datec= ui->datecirculation->date();
    QString datecirculation=datec.toString("dd/MM/yy");
   QString typecarburant=ui->typecarburant->currentText();
    QString typev=ui->typev->currentText();
   Vehicule V(matricule,numdechassis,typecarburant,typev,datecirculation,marque,idemp);
     QMessageBox msgBox;
     if(V.verifvide(matricule)==true&&V.verifvide(numdechassis)==true&&V.verifvide(idemps)==true&&V.verifint(matricule)==true)
      {     bool test=V.ajouter();
         if(test==true)
         {msgBox.setText("Ajout avec succes.");
             msgBox.setText("Ajout avec succes.");
           ui->tabvehicule->setModel(V1.afficher());
              msgBox.exec();}
                      else {
                          msgBox.setText("Echec d'ajout");
                      }
     }

     else
        { msgBox.setText("Echec d'ajout");}
         msgBox.exec();
}

void Gestioncommandes::on_ModifierVehicule_clicked()
{
    QString choix1,choix2;
      int idemp=ui->comboBoxempM->currentText().toInt();
    QString  matricule=ui->Matricule_2->text();
    QString numdechassis=ui->numerochassis_2->text();
    QString marque=ui->marquev_2->currentText();
    QDate datec= ui->datecirculation_2->date();
    QString datecirculation=datec.toString("dd/MM/yy");
   QString typecarburant=ui->typecarburant_2->currentText();
   QString typev=ui->typev_2->currentText();
Vehicule V(matricule,numdechassis,typecarburant,typev,datecirculation,marque,idemp);
     QMessageBox msgBox;
bool test=V.verifierMatricule(matricule);
     if(test&&V.verifvide(matricule)&&V.verifvide(numdechassis)&&V.verifierMatricule(matricule))
       { V.modifier();
         msgBox.setText("modificaton avec succes.");
           ui->tabvehicule->setModel(V1.afficher());
     }
     else
        { msgBox.setText("vehicule n'exite pas ");}
         msgBox.exec();

}

void Gestioncommandes::on_supprimerVehicule_clicked()
{
    Vehicule V;
       V.setmatricule(ui->supprimer->text());

          QMessageBox msgBox;
          bool test=V.verifierMatricule(V.getmatricule());
          if(test&&V.verifvide(V.getmatricule())&&V.verifierMatricule(V.getmatricule()))
             {V.supprimer(V.getmatricule());
               msgBox.setText("Suppression avec succes.");
               ui->tabvehicule->setModel(V1.afficher());

          }
          else
             {msgBox.setText("Vehicule n'existe pas");
               }

msgBox.exec();

}

void Gestioncommandes::on_cherchervehicule_clicked()
{
         int choix;
        choix=ui->combochercherv->currentIndex();
        QString linechercher=ui->lineEditvehicule->text();
        ui->tabvehicule->setModel(V1.chercher(choix,linechercher));

}

void Gestioncommandes::on_affecter_clicked()
{ QMessageBox msgBox;
   int commande=ui->affecternumcommande->currentText().toInt();
   int colis=ui->affectercolis->currentText().toInt();
   QString etat=ui->Etat->text();
           Commande_colis CC(commande,colis,etat);

  bool  test1=CC.verifvidestring(etat);

  int commande1=CC.verifiercolis(colis);

  int refclient1=CC.verifcommandeidclient(commande1);
  qDebug("test");
  int refclient=CC.verifcommandeidclient(commande);
     if(test1)
        {
           bool test2=CC.verifiercommandeaff(commande);
           if(test2==false&&CC.verifiercolis(colis)==0)
          {CC.affecteruncolis();
           msgBox.setText("Affectation avec succes.");}

          else if(test2==false&&(refclient==refclient1))
          {CC.affecteruncolis();
           msgBox.setText("Affectation avec succes.");}
           else
           { msgBox.setText("Echec de Affectation ");
           }
     }
     else
        { msgBox.setText("Echec de Affectation 2: remplir etat");
        }
     msgBox.exec();
}
//TABLE:Commande_colis
void Gestioncommandes::on_imprimer_clicked()
{  QString strStream;
  QTextStream out(&strStream);
                  const int rowCount = ui->tabcommande->model()->rowCount();
                  const int columnCount = ui->tabcommande->model()->columnCount();
                  QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                 out <<"<html>\n"
                        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      << "<title>ERP - COMmANDE LIST<title>\n "
                      << "</head>\n"
                      "<body bgcolor=#7a7a7a link=#5000A0>\n"
                      "<h1 style=\"text-align: center;\"><strong> LISTE DES COMMANDES :"+TT+"</strong></h1>"
                      "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                        "</br> </br>";

                  out << "<thead><tr bgcolor=#FFFF7F>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->tabcommande->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->tabcommande->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";


                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->tabcommande->isColumnHidden(column)) {
                              QString data =ui->tabcommande->model()->data(ui->tabcommande->model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                      }
                      out << "</tr>\n";
                  }
                  out <<  "</table>\n"
                      "</body>\n"
                      "</html>\n";

                  QTextDocument *document = new QTextDocument();
                  document->setHtml(strStream);
                  QPrinter printer;

                  QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                  if (dialog->exec() == QDialog::Accepted) {
                      document->print(&printer);
                  }

                  delete document;

}

void Gestioncommandes::on_Affichertout_clicked()
{
     ui->tabcommande->setModel(C1.afficher());
}

void Gestioncommandes::on_Affichertout_2_clicked()
{
    ui->tabvehicule->setModel(V1.afficher());
}

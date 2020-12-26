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
#include<QSqlQuery>
#include<QMediaPlayer>
Gestioncommandes::Gestioncommandes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestioncommandes)
{   ui->setupUi(this);
     ui->le_num->setValidator(new QIntValidator(0, 99999, this));
//COMBOBOX:commandes
    ui->modepaiment->addItem("cheque");
    ui->modepaiment->addItem("especes");
    ui->modepaiment->addItem("virement");
    ui->chercher->addItem("modedepaiment");
    ui->chercher->addItem("idclient");
    ui->chercher->addItem("numerocommande");
    ui->comboBoxidclient->setModel(C1.afficher_idclient());
    ui->tabcommande->setModel(C1.afficher());
    ui->idemp->setModel(C1.afficher_idemp());
  //COMBOBOX:vehicules
  ui->typecarburant->addItem("gazole");
  ui->typecarburant->addItem("Essence");
  ui->typev->addItem("camion");
  ui->typev->addItem("moto");
  ui->typev->addItem("tricycle");
  ui->marquev->addItem("Fiat");
  ui->marquev->addItem("Toyota ");
  ui->marquev->addItem("Peugeot");
  ui->marquev->addItem("Citroen");
  ui->marquev->addItem("Renault");
  ui->etat->addItem("en cours");
  ui->etat->addItem("annulee");
  ui->etat->addItem("en retard");
  //COMBOBOX:employe
  ui->comboBoxemp->setModel(V1.affiche_employer());
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
            ui->le_num->setText("");
            ui->description->setText("");
            ui->montant->setText("");
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
      int numtest=ui->le_num->text().toUInt();
      QString numstring=ui->le_num->text();
      Commande C;
      C.setnum(numtest);
     bool test1=C.verifierid(C.getnum());
     if(test1==true&&C.verifvidestring(ui->le_num->text()))
       { C.supprimer(C.getnum());
         msgBox.setText("Suppression avec succes.");

             ui->tabcommande->setModel(C1.afficher());
             ui->affecternumcommande->setModel(CC.afficher_idcommande());
             ui->le_num->setText("");
             ui->description->setText("");
             ui->montant->setText("");

            CC.updateetat(numtest);

         }
         else
          {msgBox.setText("Echec de suppression");}
             msgBox.exec();
}



void Gestioncommandes::on_ModifierCommandes_clicked()
{QMessageBox msgBox;
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
     QString idemps=ui->comboBoxemp->currentText();
    QString  matricule=ui->Matricule->text();
    QString numdechassis=ui->numerochassis->text();
    QString marque=ui->marquev->currentText();
    QDate datec= ui->datecirculation->date();
    QString datecirculation=datec.toString("dd/MM/yy");
   QString typecarburant=ui->typecarburant->currentText();
    QString typev=ui->typev->currentText();
   Vehicule V(matricule,numdechassis,typecarburant,typev,datecirculation,marque,idemps);
     QMessageBox msgBox;
     if(V.verifvide(matricule)==true&&V.verifvide(numdechassis)==true&&V.verifvide(idemps)==true&&V.verifint(matricule)==true)
      {     bool test=V.ajouter();
         if(test==true)
         {msgBox.setText("Ajout avec succes.");
             msgBox.setText("Ajout avec succes.");
           ui->tabvehicule->setModel(V1.afficher());
           ui->Matricule->setText("");
           ui->numerochassis->setText("");
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
   QString idemp=ui->comboBoxemp->currentText();
  QString  matricule=ui->Matricule->text();
  QString numdechassis=ui->numerochassis->text();
  QString marque=ui->marquev->currentText();
  QDate datec= ui->datecirculation->date();
  QString datecirculation=datec.toString("dd/MM/yy");
 QString typecarburant=ui->typecarburant->currentText();
  QString typev=ui->typev->currentText();
Vehicule V(matricule,numdechassis,typecarburant,typev,datecirculation,marque,idemp);
     QMessageBox msgBox;
bool test=V.verifierMatricule(matricule);
     if(test&&V.verifvide(matricule)&&V.verifvide(numdechassis)&&V.verifierMatricule(matricule))
       { V.modifier();
         msgBox.setText("modificaton avec succes.");
           ui->tabvehicule->setModel(V1.afficher());
           ui->Matricule->setText("");
         ui->numerochassis->setText("");
     }
     else
        { msgBox.setText("vehicule n'exite pas ");}
         msgBox.exec();

}

void Gestioncommandes::on_supprimerVehicule_clicked()
{
    Vehicule V;
       V.setmatricule(ui->Matricule->text());

          QMessageBox msgBox;
          bool test=V.verifierMatricule(V.getmatricule());
          if(test&&V.verifvide(V.getmatricule())&&V.verifierMatricule(V.getmatricule()))
             {V.supprimer(V.getmatricule());
               msgBox.setText("Suppression avec succes.");
               ui->tabvehicule->setModel(V1.afficher());
               ui->Matricule->setText("");
             ui->numerochassis->setText("");

          }
          else
             {msgBox.setText("Echec de modification");
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
   QString etat=ui->etat->currentText();
   Commande_colis CC(commande,colis,etat);
  int commande1=CC.verifiercolis(colis);//verifier est ce que le colis est affecte a une commande
  int refclient1=CC.verifcommandeidclient(commande1);// si oui return id de ce client
  int refclient=CC.verifcommandeidclient(commande); // return id de client de commande a affecter
  bool test2=CC.verifiercommandeaff(commande);  //si cette commande est deja affecte ou pas
           if(test2==false&&CC.verifiercolis(colis)==0)
          {CC.affecteruncolis();
             msgBox.setText("Affectation avec succes.");}
          else if(test2==false&&(refclient==refclient1))
          {CC.affecteruncolis();
           msgBox.setText("Affectation avec succes.");}
           else
           { msgBox.setText("Echec de Affectation ");
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

void Gestioncommandes::on_tabcommande_activated(const QModelIndex &index)
{
    QString val=ui->tabcommande->model()->data(index).toString();
    Commande *CA;
    CA=C1.readcommande(val);
    int numcommande=CA->getnum();
     float montant=CA->getmontant();
     int idclient=CA->getidclient();
      QString num_string=QString::number(numcommande);
      QString montant_string=QString::number(montant,'f',4);
      QString numclient_string=QString::number(idclient);
                ui->le_num->setText(num_string);
             ui->description->setText(CA->getdescription());
             QDate Datec=QDate::fromString((CA->getdatecommande()),("dd/MM/yy"));
               ui->datedecommande->setDate(Datec);
               ui->modepaiment->setCurrentText(CA->getmodepaiment());
               ui->montant->setText(montant_string);
               ui->idemp->setCurrentText(CA->getidemp());
               ui->comboBoxemp->setCurrentText(numclient_string);


}

void Gestioncommandes::on_tabvehicule_activated(const QModelIndex &index)
{
   QString val1=ui->tabvehicule->model()->data(index).toString();
Vehicule *VA;
   VA=V1.readvehicule(val1);
       QString idempp=VA->getidemp();
                ui->Matricule->setText(VA->getmatricule());
              ui->numerochassis->setText(VA->getnumdechassis());
              ui->marquev->setCurrentText(VA->getmarque());
              ui->typev->setCurrentText(VA->gettypev());
              ui->typecarburant->setCurrentText(VA->gettypecarburant());
              QDate Datec=QDate::fromString((VA->getdatecirculation()),("dd/MM/yy"));
             ui->datecirculation->setDate(Datec);
             ui->idemp->setCurrentText(idempp);



}

void Gestioncommandes::on_afficheraffecter_clicked()
{

    int commande=ui->affecternumcommande->currentText().toInt();
    ui->tabcommande->setModel(CC.afficher_tab(commande));

}

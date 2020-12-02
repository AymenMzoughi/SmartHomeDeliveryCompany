#include "commandewin.h"
#include "ui_commandewin.h"
#include"commande.h"
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
Commandewin::Commandewin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Commandewin)
{
    ui->setupUi(this);
    ui->modepaiment->addItem("cheque");
    ui->modepaiment->addItem("especes");
    ui->modepaiment->addItem("virement");
    ui->Mmodepaiment_2->addItem("cheque");
    ui->Mmodepaiment_2->addItem("especes");
    ui->Mmodepaiment_2->addItem("virement");
    //ui->tabcommande->setModel(C1.afficher());
    ui->chercher->addItem("modedepaiment");
    ui->chercher->addItem("idclient");
    ui->chercher->addItem("numerocommande");

}

Commandewin::~Commandewin()
{
    delete ui;
}

void Commandewin::on_supprimer_clicked()
{
    Commande C1;
      C1.setnum(ui->numsupp->text().toInt());
         bool test=C1.supprimer(C1.getnum());
         QMessageBox msgBox;
         if(test)
            { msgBox.setText("Suppression avec succes.");
         ui->tabcommande->setModel(C1.afficher());

         }
         else
            { msgBox.setText("Echec de suppression");
             msgBox.exec();}
}

void Commandewin::on_ajouter_clicked()
{
    /*QString modepaiment;
    int num=ui->le_num->text().toInt();
    QString numverif=ui->le_num->text();
    QString description=ui->description->text();
      int idclient=ui->idclient->text().toInt();
      QDate date= ui->datedecommande->date();
      QString datedecommande= date.toString("dd/MM/yy");
   modepaiment=ui->modepaiment->currentText();
    float montant=ui->montant->text().toFloat();
    //Commande C(num,description ,datedecommande,modepaiment,montant,idclient);
     QMessageBox msgBox;

     if(C.verifvidestring(C.getdatecommande())==true&&C.verifvidestring(C.getdescription())==true&&C.verifvidestring(C.getmodepaiment())==true&&C.verifvidestring(numverif)==true&&C.veriffloat(C.getmontant())==true)
       { bool test=C.ajouter();
         if(test==true)
         {msgBox.setText("Ajout avec succes.");
             msgBox.exec();
              ui->tabcommande->setModel(C1.afficher());
              QString numS=ui->le_num->text();
              QString Montant =ui->montant->text();
              QPrinter printer;
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("D:/2eme/Projet/Smart_HomeDeliveryCompany_2A9/Gestion_Commande/pdf/bondecommande("+numS+").pdf");
                      QPainter painter;
                      if(! painter.begin(&printer))
                      { qWarning("failed to open file");  }
                             painter.setFont(QFont("Arial", 30));
                              painter.setPen(Qt::black);
                          painter.drawText(50,50," Bon de commande");
                          painter.setPen(Qt::darkRed);
                      painter.drawText(100,100," Smart Home : in a Flur ");
                       painter.setPen(Qt::black);
                       painter.drawText(50,300,"numero de commande : "+numS);
                       painter.drawText(50,400,"Description  : "+description);
                       painter.drawText(50,500," Date de commande   : "+datedecommande);
                         painter.drawText(50,600," mode de paiement "+modepaiment);
                          painter.drawText(50,700,"Montant : "+Montant);
                      painter.end();}
                      else {
                          msgBox.setText("Echec d'ajout");
                           msgBox.exec();
                      }

         }
        else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();}

*/
     }

void Commandewin::on_Modifier_clicked()
{

  /*  QString modepaiment,choix;
    int num=ui->Mnum->text().toInt();
    QString description=ui->Mdescription->text();
      int idclient=ui->Midclient->text().toInt();
      QDate date= ui->Mdate->date();
        QString datedecommande= date.toString("dd/MM/yy");
   modepaiment=ui->Mmodepaiment_2->currentText();
    float montant=ui->MMontant->text().toFloat();
     QMessageBox msgBox;
    Commande C (num,description ,datedecommande,modepaiment,montant,idclient);


if(C.verifvidestring(C.getdatecommande())==true&&C.verifvidestring(C.getdescription())==true&&C.verifvidestring(C.getmodepaiment())==true&&C.veriffloat(C.getmontant())==true)
         {if(test)
         msgBox.setText("Modification avec succes");
         ui->tabcommande->setModel(C1.afficher());


         }
         else
            { msgBox.setText(" cette commande n'exite pas ");
                msgBox.exec();}
*/
}



void Commandewin::on_chercher_2_clicked()
{  int choix;
   choix=ui->chercher->currentIndex();
   QString linechercher=ui->lineEditchercher->text();
   ui->tabcommande->setModel(C1.chercher(choix,linechercher));

}

void Commandewin::on_imprimer_clicked()
{



    }


void Commandewin::on_pushButton_clicked()
{


}



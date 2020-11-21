#include "commandewin.h"
#include "ui_commandewin.h"
#include"commande.h"
#include<QPainter>
#include<QPrinter>
#include<QPdfWriter>
#include <QMessageBox>
#include<QVBoxLayout>
#include<QtDebug>
#include<QFileInfo>
#include<QFileDialog>
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
    ui->tabcommande->setModel(C1.afficher());
    ui->chercher->addItem("modedepaiment");
    ui->chercher->addItem("idclient");
    ui->chercher->addItem("Adresse");
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
    QString modepaiment;
    int num=ui->le_num->text().toInt();
    QString description=ui->description->text();
    QString adresse=ui->adresse->text();
      int idclient=ui->idclient->text().toInt();
      QDate date= ui->datedecommande->date();
        QString datedecommande= date.toString("dd/MM/yy");
   modepaiment=ui->modepaiment->currentText();
    float montant=ui->montant->text().toFloat();
    Commande C(num,description ,datedecommande,adresse,modepaiment,montant,idclient);


    bool test=C.ajouter();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");
         ui->tabcommande->setModel(C1.afficher());
     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }


}

void Commandewin::on_Modifier_clicked()
{

    QString modepaiment,choix;
    int num=ui->Mnum->text().toInt();
    QString description=ui->Mdescription->text();
    QString adresse=ui->Madresse->text();
      int idclient=ui->Midclient->text().toInt();
      QDate date= ui->Mdate->date();
        QString datedecommande= date.toString("dd/MM/yy");
      choix.sprintf("%d",ui->Mmodepaiment_2->currentIndex());
   modepaiment=ui->Mmodepaiment_2->currentText();
    float montant=ui->MMontant->text().toFloat();
    Commande C1 (num,description ,datedecommande,adresse,modepaiment,montant,idclient);
     bool test=C1.modifier();
         QMessageBox msgBox;
         if(test)
            { msgBox.setText("Modification avec succes");
         ui->tabcommande->setModel(C1.afficher());


         }
         else
            { msgBox.setText(" cette commande n'exite pas ");
             msgBox.exec();}

}



void Commandewin::on_chercher_2_clicked()
{  int choix;
   choix=ui->chercher->currentIndex();
   QString linechercher=ui->lineEditchercher->text();
   ui->tabcommande->setModel(C1.chercher(choix,linechercher));

}

void Commandewin::on_imprimer_clicked()
{QString nomFichier = QFileDialog ::getSaveFileName(0, QString::fromUtf8("Générer PDF"), QCoreApplication::applicationDirPath(), "*.pdf");

    if (!nomFichier.isEmpty())
    {
        if (QFileInfo(nomFichier).suffix().isEmpty())
            nomFichier.append(".pdf");
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(nomFichier);
        printer.setOrientation(QPrinter::Portrait);
        printer.setPaperSize(QPrinter::A4);
        printer.setPageSize(QPrinter::A4);
        printer.setPageMargins(15,15,15,15,QPrinter::Millimeter);
        printer.setPrinterName("desierd printer name");
        qDebug() << "Page px :" << printer.pageRect() << printer.paperRect();
        qDebug() << "Page mm :" << printer.pageRect(QPrinter::Millimeter) << printer.paperRect(QPrinter::Millimeter);
        qreal left, top, right, bottom;
        printer.getPageMargins(&left, &top, &right, &bottom, QPrinter::DevicePixel);
        qDebug() << "Marges px :" << left << top << right << bottom;
        printer.getPageMargins(&left, &top, &right, &bottom, QPrinter::Millimeter);
        qDebug() << "Marges mm :" << left << top << right << bottom;
          QPainter painter(&printer);
            painter.drawText(0, printer.pageRect().y()*2, QString::fromUtf8("Ligne 1"));
            printer.newPage();
            painter.drawText(0, printer.pageRect().y()*3, QString::fromUtf8("Ligne 2"));


    }


}

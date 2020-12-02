#include <QMessageBox>
#include <QVBoxLayout>
#include <QtDebug>
#include <QFileInfo>
#include <QIntValidator>
#include <QFileDialog>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "employe.h"
#include "conge.h"
#include "envoiem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);



    ui->le_id->setValidator(new QIntValidator(0,999999, this));
    ui->idemp->setValidator(new QIntValidator(0,999999, this));
    ui->le_idc->setValidator(new QIntValidator(0,999999, this));
    ui->le_id_2->setValidator(new QIntValidator(0,999999, this));
    ui->Midc->setValidator(new QIntValidator(0,999999, this));
    ui->Mid->setValidator(new QIntValidator(0,999999, this));
    ui->Sidc->setValidator(new QIntValidator(0,999999, this));
    ui->Midem->setValidator(new QIntValidator(0,999999, this));
    ui->Mduree->setValidator(new QIntValidator(0,999999, this));
    ui->dur->setValidator(new QIntValidator(0,999999, this));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);


    int idemp=ui->le_id->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QDate date= ui->la_dns->date();
     QString dns= date.toString("dd/MM/yy");
   int numtel=ui->le_numtel->text().toInt();
   QString adr=ui->le_adr->text();
   QString mail=ui->le_mail->text();
   Employe E(idemp,nom,prenom,dns,numtel,adr,mail);
   bool test1=(controleEmail(mail)&&controlenum(numtel)&&controleVide(prenom)&&controleVide(nom)&&controleVide(adr));
   bool test=E.ajouter();
    QMessageBox msgBox;

    if(test&&test1)
      {  msgBox.setText("Ajout avec succes.");
    msgBox.exec();
    ui->tabemp->setModel(E1.afficher());
    }

    else
       { msgBox.setText("Echec d'ajout, verifier les champs");
        msgBox.exec();
   }
}



void MainWindow::on_chercher_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    int choix;
       choix=ui->chercherchoix->currentIndex();
       QString linechercher=ui->cherchertext->text();
       ui->tabemp->setModel(E1.chercher(choix,linechercher));
}


void MainWindow::on_supprimer_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    Employe E1;
      E1.setidemp(ui->idemp->text().toInt());
         bool test=E1.supprimer(E1.getidemp());
         if(test)
       {
       QMessageBox::information(nullptr, QObject::tr("Suppression terminer"),
                         QObject::tr("Modification faite\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabemp->setModel(E1.afficher());
       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Suppression echouée"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }


void MainWindow::on_modifier_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    int idemp=ui->Midem->text().toInt();
    QString nom=ui->Mnom->text();
    QString prenom=ui->Mprenom->text();
    QDate date= ui->Mdns->date();
      QString Mdns= date.toString("dd/MM/yy");
    int numtel=ui->Mnumtel->text().toInt();
    QString adr=ui->Madr->text();
    QString mail=ui->Mmail->text();
    Employe E1 (idemp,nom,prenom,Mdns,numtel,adr,mail);
     bool test=E1.modifier();
      bool test1=(controleEmail(mail)&&controlenum(numtel)&&controleVide(prenom)&&controleVide(nom)&&controleVide(adr));
     if(test&&test1)
   {
   QMessageBox::information(nullptr, QObject::tr("Modification faite"),
                     QObject::tr("Modification faite\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabemp->setModel(E1.afficher());
   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modification non faite"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_pb_ajouterc_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);


    int idc=ui->le_idc->text().toInt();
    int idemp=ui->le_id_2->text().toInt();
    QString nom=ui->le_nomc->text();
    QString prenom=ui->le_prenomc->text();
    QDate datedeb= ui->deb->date();
      QString deb= datedeb.toString("dd/MM/yy");
    QDate datefin= ui->fin->date();
      QString fin= datefin.toString("dd/MM/yy");
    int duree=ui->dur->text().toInt();
    QString etat=ui->etat->text();
    Conge C(idc,nom,prenom,deb,fin,duree,etat,idemp);

    bool test=C.ajouterc();
     bool test1=(controleVide(prenom)&&controleVide(nom)&&controleVide(etat));
     QMessageBox msgBox;

     if(test&&test1)
       {  msgBox.setText("Ajout avec succes.");
     msgBox.exec();
     ui->tabcong->setModel(C1.afficherc());
     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }

}

void MainWindow::on_pb_modifierc_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);


    int idc=ui->Midc->text().toInt();
    int idemp=ui->Mid->text().toInt();
    QString nom=ui->Mnomc->text();
    QString prenom=ui->Mprenomc->text();
    QDate datedeb= ui->Mdeb->date();
      QString Mdeb= datedeb.toString("dd/MM/yy");
    QDate datefin= ui->Mfin->date();
      QString Mfin= datefin.toString("dd/MM/yy");
    int duree=ui->Mduree->text().toInt();
    QString etat=ui->Metat->text();

    Conge C1(idc,nom,prenom,Mdeb,Mfin,duree,etat,idemp);
    bool test=C1.modifierc();
    bool test1=(controleVide(prenom)&&controleVide(nom)&&controleVide(etat));
     QMessageBox msgBox;

     if(test&&test1)
       {  QMessageBox::information(nullptr, QObject::tr("Modification faite"),
                                   QObject::tr("Modification faite\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabcong->setModel(C1.afficherc());
                 }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Modification non faite"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}

void MainWindow::on_pb_supprimerc_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);


    Conge C1;
      C1.setidc(ui->Sidc->text().toInt());
         bool test=C1.supprimerc(C1.getidc());
         if(test)
       {
       QMessageBox::information(nullptr, QObject::tr("Suppression terminer"),
                         QObject::tr("Modification faite\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabcong->setModel(C1.afficherc());
       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Suppression echouée"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherchec_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    int choix;
       choix=ui->choix->currentIndex();
       QString linechercher=ui->text->text();
       ui->tabcong->setModel(C1.chercherc(choix,linechercher));
}

void MainWindow::on_affichage_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    ui->tabemp->setModel(E1.afficher());
}



void MainWindow::on_TrierC_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    int choix2;
       choix2=ui->choix2->currentIndex();
       ui->tabcong->setModel(C1.trierc(choix2));
}

void MainWindow::on_affichagec_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    ui->tabcong->setModel(C1.afficherc());
}


bool MainWindow::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@' )
        {
            return true;
        }
    }
   {
    QMessageBox::critical(nullptr, QObject::tr("Ajout echouée"),
                QObject::tr("Verifier Email @\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    return false;}
}
bool MainWindow::controlenum(int test)
{
    QString tel= QString::number(test);
    for(int i=0;i<tel.length();i++)
    {
        if (tel.length()==8)
        {
            return true;
        }
    }
    {
    QMessageBox::critical(nullptr, QObject::tr("Ajout echouée"),
                QObject::tr("Verifier numero\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
return false;
    }
}
bool MainWindow::controleVide(QString test)
{
    if(test!="")
        return  true;

    {
    QMessageBox::critical(nullptr, QObject::tr("Ajout echouée"),
                QObject::tr("Champs vide\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    return false;}
}


void MainWindow::on_pushButton_27_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    Envoiem m;
    m.setModal(true);
    m.exec();
}

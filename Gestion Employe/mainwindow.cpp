#include <QMessageBox>
#include <QVBoxLayout>
#include <QtDebug>
#include <QFileInfo>
#include <QIntValidator>
#include <QFileDialog>
#include <QPixmap>
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
    QPixmap pix("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/img/Emplyé.png");
    ui->photoEmp->setPixmap(pix);

    QPixmap pix2("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/img/Congé.png");
    ui->photoCong->setPixmap(pix2);

    ui->le_id->setValidator(new QIntValidator(0,999999, this));
    ui->le_numtel->setValidator(new QIntValidator(0,99999999, this));
    ui->le_idc->setValidator(new QIntValidator(0,999999, this));
    ui->le_id_2->setValidator(new QIntValidator(0,999999, this));
    ui->dur->setValidator(new QIntValidator(0,999999, this));

    ui->tabemp->setModel(E1.afficher());

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

    QMessageBox msgBox;
  //bool test1=E.controlemail(mail);
    if(test1==true&&E.verifid(idemp)==false)
      {  msgBox.setText("Ajout avec succes.");
   E.ajouter();
    ui->tabemp->setModel(E1.afficher());
    }

    else
       { msgBox.setText("Echec d'ajout, verifier les champs");

   }
     msgBox.exec();
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
      E1.setidemp(ui->le_id->text().toInt());
         bool test=E1.verifid(E1.getidemp());
         if(test)
       {E1.supprimer(E1.getidemp());
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

    int idemp=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QDate date= ui->la_dns->date();
      QString dns= date.toString("dd/MM/yy");
    int numtel=ui->le_numtel->text().toInt();
    QString adr=ui->le_adr->text();
    QString mail=ui->le_mail->text();
    Employe E1 (idemp,nom,prenom,dns,numtel,adr,mail);
     bool test=E1.verifid(idemp);
      bool test1=(controleEmail(mail)&&controlenum(numtel)&&controleVide(prenom)&&controleVide(nom)&&controleVide(adr));
     if(test&&test1)
   {E1.modifier();
   QMessageBox::information(nullptr, QObject::tr("Modification faite"),
                     QObject::tr("Modification faite\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabemp->setModel(E1.afficher());
   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modification non faite"),
                     QObject::tr("Echec d'ajout, verifier les champs.\n"
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

    bool test=C.verifid(idc);
    bool test1=(controleVide(prenom)&&controleVide(nom)&&controleVide(etat));
     QMessageBox msgBox;
     if(test==false&&test1)
       {  C.ajouterc();
         msgBox.setText("Ajout avec succes.");

     ui->tabconge->setModel(C1.afficherc());
     }
     else
        { msgBox.setText("Echec d'ajout, verifier les champs.");

    }
 msgBox.exec();
}

void MainWindow::on_pb_modifierc_clicked()
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
      QString Mdeb= datedeb.toString("dd/MM/yy");
    QDate datefin= ui->fin->date();
      QString Mfin= datefin.toString("dd/MM/yy");
    int duree=ui->dur->text().toInt();
    QString etat=ui->etat->text();

    Conge C1(idc,nom,prenom,Mdeb,Mfin,duree,etat,idemp);
    bool test=C1.verifid(idc);
    bool test1=(controleVide(prenom)&&controleVide(nom)&&controleVide(etat));
     QMessageBox msgBox;

     if(test&&test1)
       {
         C1.modifierc();
         QMessageBox::information(nullptr, QObject::tr("Modification faite"),
                                   QObject::tr("Modification faite\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabconge->setModel(C1.afficherc());
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
      C1.setidc(ui->le_idc->text().toInt());
         bool test=C1.verifid(C1.getidc());
         if(test)
       {C1.supprimerc(C1.getidc());
       QMessageBox::information(nullptr, QObject::tr("Suppression terminer"),
                         QObject::tr("Modification faite\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabconge->setModel(C1.afficherc());
       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Suppression echouée"),
                         QObject::tr("Echec d'ajout, verifier les champs.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherchec_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    int choix;
       choix=ui->choixR->currentIndex();
       QString linechercher=ui->choix->text();
       ui->tabconge->setModel(C1.chercherc(choix,linechercher));
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
       choix2=ui->choixT->currentIndex();
       ui->tabconge->setModel(C1.trierc(choix2));
}

void MainWindow::on_affichagec_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/TheBoss'07/Desktop/SmartHomeDeliveryCompany/Gestion Employe/son/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);

    ui->tabconge->setModel(C1.afficherc());
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

void MainWindow::on_tabemp_activated(const QModelIndex &index)
{

QString val=ui->tabemp->model()->data(index).toString();
Employe *EM;
EM=E1.reademploye(val);
  int idemp=EM->getidemp();
  int numtel=EM->getnumtel();
  QString idemp_string=QString::number(idemp);
  QString numtel_string=QString::number(numtel);


        ui->le_id->setText(idemp_string);
        ui->le_numtel->setText(numtel_string);
        ui->le_nom->setText(EM->getnom());
        ui->le_prenom->setText(EM->getprenom());
         QDate dns=QDate::fromString((EM->getdate()),("dd/MM/yy"));
           ui->la_dns->setDate(dns);
           ui->le_adr->setText(EM->getadr());
           ui->le_mail->setText(EM->getmail());

}

void MainWindow::on_tabconge_activated(const QModelIndex &index)
{
    QString val=ui->tabconge->model()->data(index).toString();
    Conge *CN;
    CN=C1.readconge(val);
      int idemp=CN->getidemp();
      int idc=CN->getidc();
      int dur=CN->getduree();
      QString idemp_string=QString::number(idemp);
      QString idc_string=QString::number(idc);
      QString dur_string=QString::number(dur);


            ui->le_id_2->setText(idemp_string);
            ui->le_idc->setText(idc_string);
            ui->dur->setText(dur_string);

            ui->le_nomc->setText(CN->getnom());
            ui->le_prenomc->setText(CN->getprenom());

            QDate deb=QDate::fromString((CN->getdatedeb()),("dd/MM/yy"));
               ui->la_dns->setDate(deb);
             QDate fin=QDate::fromString((CN->getdatefin()),("dd/MM/yy"));
               ui->la_dns->setDate(fin);

               ui->etat->setText(CN->getetat());

}

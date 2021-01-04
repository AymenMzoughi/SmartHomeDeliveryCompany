#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QPixmap>
#include"employe.h"
#include "envoyermail.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->stackedWidget1->setCurrentIndex(0);
   //ui->stackedwidget_rfid->setCurrentIndex(0);
   QPixmap pix("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Emplyé.png");
   ui->photoEm->setPixmap(pix);
   QPixmap pix2("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Congé.png");
   ui->photoCong_2->setPixmap(pix2);
   QPixmap pix3("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Commandes.png");
   ui->photoCmd->setPixmap(pix3);
   QPixmap pix4("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Vehicules.png");
   ui->photoVeh->setPixmap(pix4);

   QPixmap pix5("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/login.png");
   ui->loginp->setPixmap(pix5);
   QPixmap pix6("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/PageA.png");
   ui->pa->setPixmap(pix6);

   QPixmap pix7("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Clients.png");
   ui->photoCli->setPixmap(pix7);
   QPixmap pix8("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Carte Fid.png");
   ui->photoFid->setPixmap(pix8);
   QPixmap pix9("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/Colis.png");
   ui->photoColis->setPixmap(pix9);
   QPixmap pix10("C:/Users/TheBoss'07/Desktop/Projet/Smart_HomeDeliveryCompany_2A9/code intégration/img/entrepots.png");
   ui->photoEntr->setPixmap(pix10);
    //******************************amine******************************//
   ui->le_telephone_client->setValidator(new QIntValidator(10000000, 99999999, this));

   ui->le_cheque_cf->setValidator(new QIntValidator(100000, 999999, this));
   ui->le_num_cf->setValidator(new QIntValidator(1000, 9999, this));

   ui->cb_num_supp->setModel(CF.afficher_numero());
   ui->le_ref_client->setValidator(new QIntValidator(10000, 99999, this));


   ui->le_points_cf->setValidator(new QIntValidator(100, 999, this));
   ui->tab_client->setModel(E.afficher());
   ui->tab_cf->setModel(CF.afficher());
   ui->comboBox_refer_cf->setModel(CF.afficher_ref());

   ui->cb_reff_modif->setModel(E.afficher_reference());

   //music
   player=new QMediaPlayer(this);
   connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);

   //**********************************ZEINEB*******************************************//
   ui->le_num->setValidator(new QIntValidator(0, 99999, this));
//COMBOBOX:commandes
  ui->modepaiment->addItem("cheque");
  ui->modepaiment->addItem("especes");
  ui->modepaiment->addItem("virement");
  ui->chercher->addItem("modedepaiment");
  ui->chercher->addItem("idclient");
  ui->chercher->addItem("numerocommande");
  ui->comboBoxidclient->setModel(CO1.afficher_idclient());
  ui->tabcommande->setModel(CO1.afficher());
  ui->idemp->setModel(CO1.afficher_idemp());
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
 /***************************mariem***************************/
  ui->tabcolis->setModel(Cl1.afficher());
  ui->comboBox_colis->addItem("longeur");
   ui->comboBox_colis->addItem("poids");
    ui->comboBox_colis->addItem("code barre ");

    ui->comboBox_tri->addItem("code barre");
    ui->comboBox_tri->addItem("poids");
      ui->comboBox_tri->addItem("largeur");
      ui->comboBox_tri22->addItem("ref");
      ui->comboBox_tri22->addItem("region");
      ui->comboBox_tri22->addItem("numsalle");
      ui->comboBox_entro->addItem("ref");
      ui->comboBox_entro->addItem("adresse");
      ui->comboBox_entro->addItem("region");
      ui->comboBox_entro->addItem("num salle");
      ui->tabentrep->setModel(ET1.afficher());




//ard
 int ret=A.connect_arduino(); // lancer la connexion à arduino
 switch(ret){
 case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
     break;
 case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
    break;
 case(-1):qDebug() << "arduino is not available";
 }
  QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_rfid())); // permet de lancer
}

MainWindow::~MainWindow()
{
    delete ui;
    A.close_arduino();
    delete player;

}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    // si les données reçues de arduino via la liaison série sont égales à 1*/
}
void MainWindow::on_Commande_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    /*ui->pushButtonclients->setDisabled(true);
    ui->pushButtonemployees->setDisabled(true);
    ui->pushButtonstock->setDisabled(true);
    ui->pushButtonsav->setDisabled(true);
    ui->pushButtonclients->setDisabled(true);
    ui->Commande->setDisabled(false);*/



}


void MainWindow::on_pushButtonemployees_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButtonclients_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_pushButtonstock_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(5);
}

void MainWindow::on_pushButtonsav_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pageacc_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pb_clear_clicked()
{
    ui->le_password->setText("");
    ui->le_username->setText("");
}

void MainWindow::on_pb_login_clicked()
{
    QString RecupRole;
    QString Username, Password , role;
   Username =ui->le_username->text();
    Password=ui->le_password->text();
 Admin A1(Username,Password,role);

 bool test=A1.Login();
RecupRole=A1.afficherRole();
//qDebug()<<RecupRole;
ui->le_role->setText(RecupRole);
 if(test)
 {

     ui->label_3->setText("[+]Valid username or password ");

     if(RecupRole=="admin")
     {

          ui->label_3->setText("[+]Valid username and password ");
        ui->stackedWidget1->setCurrentIndex(1);
        ui->pushButtonclients->setDisabled(false);
        ui->pushButtonemployees->setDisabled(false);
        ui->pushButtonsav->setDisabled(false);
        ui->Commande->setDisabled(false);
        ui->pushButtonstock->setDisabled(false);
        ui->le_user_rfid->setText("Admin");
        ui->le_email_rfid->setText("Admin@gmail.com");
        ui->le_depart_rfid->setText("Administrateur");
        QPixmap pix("C:/Users/Amine/Desktop/assistants photos/admin");
        ui->le_photo->setPixmap(pix.scaled(100,100));




     }else if(RecupRole=="assistantStock")
     {
         ui->stackedWidget1->setCurrentIndex(1);
         ui->stackedWidget_2->setCurrentIndex(5);
           ui->pushButtonclients->setDisabled(true);
           ui->pushButtonemployees->setDisabled(true);
           ui->pushButtonsav->setDisabled(true);
           ui->Commande->setDisabled(true);
          ui->pushButtonstock->setDisabled(false);

    }else if(RecupRole=="assistantEmploye")
     {
         ui->stackedWidget1->setCurrentIndex(1);
         ui->stackedWidget_2->setCurrentIndex(1);
         ui->pushButtonclients->setDisabled(true);
         ui->pushButtonsav->setDisabled(true);
         ui->pushButtonstock->setDisabled(true);
         ui->Commande->setDisabled(true);

         ui->pushButtonemployees->setDisabled(false);
      }else if(RecupRole=="assistantClient")
     {
         ui->stackedWidget1->setCurrentIndex(1);
         ui->stackedWidget_2->setCurrentIndex(4);
         ui->pushButtonsav->setDisabled(true);
         ui->pushButtonemployees->setDisabled(true);
         ui->pushButtonstock->setDisabled(true);
         ui->Commande->setDisabled(true);
         ui->pushButtonclients->setDisabled(false);

         ui->label_3->setText("accés authorisé");
         ui->le_user_rfid->setText("mohamed amine aouididi");
         ui->le_email_rfid->setText("amine@gmail.com");
         ui->le_depart_rfid->setText("assistant de la gestion des clients");
         QPixmap pix("C:/Users/Amine/Desktop/assistants photos/amine");
         ui->le_photo->setPixmap(pix.scaled(100,100));

     }else if(RecupRole=="assistantCommande")
     {
         ui->stackedWidget1->setCurrentIndex(1);
         ui->stackedWidget_2->setCurrentIndex(0);
         ui->pushButtonclients->setDisabled(true);
         ui->pushButtonemployees->setDisabled(true);
         ui->pushButtonstock->setDisabled(true);
         ui->pushButtonsav->setDisabled(true);
         ui->Commande->setDisabled(false);
     }else if(RecupRole=="assistantSAV")
     {
         ui->stackedWidget1->setCurrentIndex(1);
         ui->stackedWidget_2->setCurrentIndex(3);
         ui->pushButtonclients->setDisabled(true);
         ui->pushButtonemployees->setDisabled(true);
         ui->pushButtonstock->setDisabled(true);
         ui->Commande->setDisabled(true);
         ui->pushButtonsav->setDisabled(false);

     }
  }else {
       ui->label_3->setText("[!]wrong username or password :( ");
      }


}



void MainWindow::on_pushButton_clicked()
{


    ui->stackedWidget1->setCurrentIndex(0);

    //show();
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int idemp=ui->le_id_3->text().toInt();
   QString nom=ui->le_nom_2->text();
   QString prenom=ui->le_prenom_2->text();
   QDate date= ui->la_dns_2->date();
     QString dns= date.toString("dd/MM/yy");
   int numtel=ui->le_numtel_2->text().toInt();
   QString adr=ui->le_adr_2->text();
   QString mail=ui->le_mail_2->text();
   Employe E(idemp,nom,prenom,dns,numtel,adr,mail);
   QString tel=ui->le_numtel_2->text();
   Commande C;
    QMessageBox msgBox;
  bool test1=E.controlemail(mail);
    if(test1==true&&E.verifid(idemp)==false&&C.verifvidestring(nom)&&C.verifvidestring(prenom)&&C.verifvidestring(adr)&&E.controletel(tel))
      {  msgBox.setText("Ajout avec succes.");
   E.ajouter();
    ui->tabemp_2->setModel(E1.afficher());
    ui->comboBoxemp->setModel(V1.affiche_employer());
     ui->idemp->setModel(CO1.afficher_idemp());

    }

    else
       { msgBox.setText("Echec d'ajout, verifier les champs");

   }
     msgBox.exec();
}

void MainWindow::on_pb_modifierc_2_clicked()
{     int idc=ui->le_idc_2->text().toInt();
      int idemp=ui->le_id_4->text().toInt();
      QString nom=ui->le_nomc_2->text();
      QString prenom=ui->le_prenomc_2->text();
      QDate datedeb= ui->deb_2->date();
        QString deb= datedeb.toString("dd/MM/yy");
      QDate datefin= ui->fin_2->date();
        QString fin= datefin.toString("dd/MM/yy");
      int duree=ui->dur_2->text().toInt();
      QString etat=ui->etat_3->text();
    Conge C1(idc,nom,prenom,deb,fin,duree,etat,idemp);
    bool test=C1.verifid(idc);
    //bool test1=(controleVide(prenom)&&controleVide(nom)&&controleVide(etat));
     QMessageBox msgBox;

     if(test)
       {
         C1.modifierc();
         QMessageBox::information(nullptr, QObject::tr("Modification faite"),
                                   QObject::tr("Modification faite\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabconge_2->setModel(C1.afficherc());
                 }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Modification non faite"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);


    //

}

void MainWindow::on_pb_supprimerc_2_clicked()
{
    Conge C1;
      C1.setidc(ui->le_idc_2->text().toInt());
         bool test=C1.verifid(C1.getidc());
         if(test)
       {C1.supprimerc(C1.getidc());
       QMessageBox::information(nullptr, QObject::tr("Suppression terminer"),
                         QObject::tr("Modification faite\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabconge_2->setModel(C1.afficherc());
       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Suppression echouée"),
                         QObject::tr("Echec d'ajout, verifier les champs.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_affichagec_2_clicked()
{
   ui->tabconge_2->setModel(C1.afficherc());
}

void MainWindow::on_recherchec_2_clicked()
{


    int choix;
       choix=ui->choixR_2->currentIndex();
       QString linechercher=ui->choix_2->text();
       ui->tabconge_2->setModel(C1.chercherc(choix,linechercher));
}

void MainWindow::on_chercher_3_clicked()
{
    int choix;
       choix=ui->chercherchoix_2->currentIndex();
       QString linechercher=ui->cherchertext_2->text();
       ui->tabemp_2->setModel(E1.chercher(choix,linechercher));
}

void MainWindow::on_affichage_2_clicked()
{
    ui->tabemp_2->setModel(E1.afficher());
}

void MainWindow::on_tabemp_2_activated(const QModelIndex &index)
{
    QString val=ui->tabemp_2->model()->data(index).toString();
    Employe *EM;
    EM=E1.reademploye(val);
      int idemp=EM->getidemp();
      int numtel=EM->getnumtel();
      QString idemp_string=QString::number(idemp);
      QString numtel_string=QString::number(numtel);


            ui->le_id_3->setText(idemp_string);
            ui->le_numtel_2->setText(numtel_string);
            ui->le_nom_2->setText(EM->getnom());
            ui->le_prenom_2->setText(EM->getprenom());
             QDate dns=QDate::fromString((EM->getdate()),("dd/MM/yy"));
               ui->la_dns_2->setDate(dns);
               ui->le_adr_2->setText(EM->getadr());
               ui->le_mail_2->setText(EM->getmail());
}

void MainWindow::on_pb_ajouterc_2_clicked()
{
    int idc=ui->le_idc_2->text().toInt();
    int idemp=ui->le_id_4->text().toInt();
    QString nom=ui->le_nomc_2->text();
    QString prenom=ui->le_prenomc_2->text();
    QDate datedeb= ui->deb_2->date();
      QString deb= datedeb.toString("dd/MM/yy");
    QDate datefin= ui->fin_2->date();
      QString fin= datefin.toString("dd/MM/yy");
    int duree=ui->dur_2->text().toInt();
    QString etat=ui->etat_3->text();
    Conge C(idc,nom,prenom,deb,fin,duree,etat,idemp);
   Commande CC;
    bool test=C.verifid(idc);
   //bool test1=(controleVide(prenom)&&controleVide(nom)&&controleVide(etat));
     QMessageBox msgBox;
     if(test==false&&C.ajouterc()&&CC.verifvidestring(nom)&&CC.verifvidestring(prenom)&&CC.verifvidestring(etat))
       {
         msgBox.setText("Ajout avec succes.");

     ui->tabconge_2->setModel(C1.afficherc());
     }
     else
        { msgBox.setText("Echec d'ajout, verifier les champs.");

    }
 msgBox.exec();
}

void MainWindow::on_modifier_2_clicked()
{
    int idemp=ui->le_id_3->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QDate date= ui->la_dns_2->date();
      QString dns= date.toString("dd/MM/yy");
    int numtel=ui->le_numtel_2->text().toInt();
    QString adr=ui->le_adr_2->text();
    QString mail=ui->le_mail_2->text();
    Employe E1 (idemp,nom,prenom,dns,numtel,adr,mail);
    Commande CC;
    bool test=E1.verifid(idemp);

     if(test==false&&CC.verifvidestring(nom)&&CC.verifvidestring(prenom)&&CC.verifvidestring(adr))
   {E1.modifier();
   QMessageBox::information(nullptr, QObject::tr("Modification faite"),
                     QObject::tr("Modification faite\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabemp_2->setModel(E1.afficher());
   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modification non faite"),
                     QObject::tr("Echec d'ajout, verifier les champs.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_2_clicked()
{
    Employe E2;
      E2.setidemp(ui->le_id_3->text().toInt());
         bool test=E2.verifid(E2.getidemp());
         if(test)
       {E2.supprimer(E2.getidemp());
       QMessageBox::information(nullptr, QObject::tr("Suppression terminer"),
                         QObject::tr("Modification faite\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
ui->tabemp_2->setModel(E1.afficher());
       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Suppression echouée"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_TrierC_2_clicked()
{
    int choix2;
       choix2=ui->choixT_2->currentIndex();
       ui->tabconge_2->setModel(C1.trierc(choix2));
}

void MainWindow::on_tabconge_2_activated(const QModelIndex &index)
{
    QString val=ui->tabconge_2->model()->data(index).toString();
    Conge *CN;
    CN=C1.readconge(val);
      int idemp=CN->getidemp();
      int idc=CN->getidc();
      int dur=CN->getduree();
      QString idemp_string=QString::number(idemp);
      QString idc_string=QString::number(idc);
      QString dur_string=QString::number(dur);


            ui->le_id_4->setText(idemp_string);
            ui->le_idc_2->setText(idc_string);
            ui->dur_2->setText(dur_string);

            ui->le_nomc_2->setText(CN->getnom());
            ui->le_prenomc_2->setText(CN->getprenom());

            QDate deb=QDate::fromString((CN->getdatedeb()),("dd/MM/yy"));
               ui->la_dns_2->setDate(deb);
             QDate fin=QDate::fromString((CN->getdatefin()),("dd/MM/yy"));
               ui->la_dns_2->setDate(fin);

               ui->etat_3->setText(CN->getetat());
}

void MainWindow::on_ajouterCommandes_clicked()
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
            ui->tabcommande->setModel(CO1.afficher());
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

void MainWindow::on_ModifierCommandes_clicked()
{
    QMessageBox msgBox;
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
               ui->tabcommande->setModel(CO1.afficher());
               }

               else
                { msgBox.setText(" Echec de modification ");
                    }
    msgBox.exec();
}

void MainWindow::on_supprimerCommandes_clicked()
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

           ui->tabcommande->setModel(CO1.afficher());
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

void MainWindow::on_chercher_2Commandes_clicked()
{
    int choix;
        choix=ui->chercher->currentIndex();
        QString linechercher=ui->lineEditchercher->text();
        ui->tabcommande->setModel(CO1.chercher(choix,linechercher));
}

void MainWindow::on_Affichertout_clicked()
{
      ui->tabcommande->setModel(CO1.afficher());
}

void MainWindow::on_imprimer_clicked()
{
    QString strStream;
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

void MainWindow::on_affecter_clicked()
{
    QMessageBox msgBox;
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

void MainWindow::on_afficheraffecter_clicked()
{
    int commande=ui->affecternumcommande->currentText().toInt();
    ui->tabcommande->setModel(CC.afficher_tab(commande));
}

void MainWindow::on_tabcommande_activated(const QModelIndex &index)
{
    QString val=ui->tabcommande->model()->data(index).toString();
    Commande *CA;
    CA=CO1.readcommande(val);
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

void MainWindow::on_AjouterVehicule_clicked()
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

void MainWindow::on_supprimerVehicule_clicked()
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

void MainWindow::on_ModifierVehicule_clicked()
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

void MainWindow::on_cherchervehicule_clicked()
{
    int choix;
   choix=ui->combochercherv->currentIndex();
   QString linechercher=ui->lineEditvehicule->text();
   ui->tabvehicule->setModel(V1.chercher(choix,linechercher));
}

void MainWindow::on_Affichertout_2_clicked()
{
     ui->tabvehicule->setModel(V1.afficher());
}

void MainWindow::on_tabvehicule_activated(const QModelIndex &index)
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

void MainWindow::on_statistique_clicked()
{
    s=new Statistique_veh(this);
       s->show();
}

/*void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedwidget_rfid->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedwidget_rfid->setCurrentIndex(0);
}*/
void MainWindow::update_rfid()
{
    data = A.read_from_arduino();
    int i;
    if(data=="8")
    {numdesv++;
     numplace--;
    QString numv_string=QString::number(numdesv);
    QString nump_string=QString::number(numplace);
       ui->le_ve_2->setText(numv_string);
      ui->le_pd_2->setText(nump_string);}
        for(i=0; i<=5; i++)
       { if(data=="1")
        {
            ui->label_3->setText("accés authorisé");
            ui->le_user_rfid->setText("mohamed amine aouididi");
            ui->le_email_rfid->setText("amine@gmail.com");
            ui->le_depart_rfid->setText("assistant de la gestion des clients");
            QPixmap pix("C:/Users/Amine/Desktop/assistants photos/amine");
            ui->le_photo->setPixmap(pix.scaled(100,100));
            ui->stackedWidget1->setCurrentIndex(1);
            ui->stackedWidget_2->setCurrentIndex(4);
            ui->pushButtonsav->setDisabled(true);
            ui->pushButtonemployees->setDisabled(true);
            ui->pushButtonstock->setDisabled(true);
            ui->Commande->setDisabled(true);
            ui->pushButtonclients->setDisabled(false);

        }else if(data=="2")
        {
                ui->label_3->setText("accés authorisé");
                ui->le_user_rfid->setText("Admin");
                ui->le_email_rfid->setText("Admin@gmail.com");
                ui->le_depart_rfid->setText("Administrateur");
                QPixmap pix("C:/Users/Amine/Desktop/assistants photos/admin");
                ui->le_photo->setPixmap(pix.scaled(100,100));

                ui->stackedWidget1->setCurrentIndex(1);
                ui->pushButtonclients->setDisabled(false);
                ui->pushButtonemployees->setDisabled(false);
                ui->pushButtonsav->setDisabled(false);
                ui->Commande->setDisabled(false);
                ui->pushButtonstock->setDisabled(false);

        }else if(data=="0")
        {
            ui->label_3->setText("access denied");
            ui->le_user_rfid->setText("");
            ui->le_email_rfid->setText("");
            ui->le_depart_rfid->setText("");
            QPixmap pix("C:/Users/Amine/Desktop/assistants photos/black screen");
            ui->le_photo->setPixmap(pix.scaled(100,100));
        }
       }
}





bool MainWindow::controlTel(int test)
{
    QString tel= QString::number(test);
    for(int i=0;i<tel.length();i++)
    {
        if (tel.length()==8)
        {
            return true;
        }
    }
    return false;
}
bool MainWindow::controlRef(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()==5)
        {
            return true;
        }
    }
    return false;
}
bool MainWindow::controlVide(QString test)
{
    if(test!="")
        return  true;
    return false;
}
bool MainWindow::controlEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}
bool MainWindow:: controlNumero(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()==4)
        {
            return true;
        }
    }
    return false;
}
bool MainWindow::controlPoints(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()==3)
        {
            return true;
        }
    }
    return false;
}
bool MainWindow:: controlCheque(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()==6)
        {
            return true;
        }
    }
    return false;
}



void MainWindow::on_slider_volume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_start_clicked()
{
    //load the file
    player->setMedia(QUrl::fromLocalFile("C:/Users/Amine/Desktop/projetcpp/music.mp3"));
    player->play();
    qDebug()<< player->errorString();
}

void MainWindow::on_pause_clicked()
{
    player->stop();
}


void MainWindow::on_positionChanged(qint64 position)
{
    ui->slider_volume->setMaximum(position);
}

void MainWindow::on_tab_cf_activated(const QModelIndex &index)
{
    QString val=ui->tab_cf->model()->data(index).toString();



      QSqlQuery qry;
    qry.prepare("select * from cartefidelite where numero= '"+val+"' or cheque='"+val+"' or points='"+val+"' or refer_clients='"+val+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_num->setText(qry.value(0).toString());
            ui->le_points_cf->setText(qry.value(1).toString());
            ui->le_cheque_cf->setText(qry.value(2).toString());
            ui->comboBox_refer_cf->setCurrentText(qry.value(5).toString());
            ui->cb_num_supp->setCurrentText(qry.value(0).toString());

        };


    }


}

void MainWindow::on_tab_client_activated(const QModelIndex &index)
{
    QString val=ui->tab_client->model()->data(index).toString();


    QSqlQuery qry;
    qry.prepare("select * from clients where Ref_c='"+val+"' or telephone ='"+val+"' or nom_c='"+val+"' or Email='"+val+"' or pays='"+val+"' or adresse='"+val+"'  ");
    if(qry.exec())
    {
        while(qry.next())
        {
          ui->le_ref_client->setText(qry.value(0).toString());

          ui->le_Email_client->setText(qry.value(1).toString());
           ui->le_telephone_client->setText(qry.value(2).toString());
          ui->le_nom_client->setText(qry.value(3).toString());
          ui->le_adresse_client->setText(qry.value(4).toString());
          ui->le_pays_client->setText(qry.value(5).toString());

          ui->cb_reff_modif->setCurrentText(qry.value(0).toString());
        };
    }
}


void MainWindow::on_pb_envoyermail_client_clicked()
{
    EnvoyerMail E;
    E.setModal(true);
    E.exec();
}

void MainWindow::on_pb_ajout_client_clicked()
{

    int telephone=ui->le_telephone_client->text().toInt();
    int Ref_c=ui->le_ref_client->text().toInt();
    QString Email=ui->le_Email_client->text();
    QString nom_c=ui->le_nom_client->text();
    QString pays=ui->le_pays_client->text();
    QString adresse=ui->le_adresse_client->text();
Clients C(Ref_c,telephone,Email,nom_c,pays,adresse);
bool test1=((controlEmail(Email))&&(controlRef(Ref_c))&&(controlTel(telephone))&&(controlVide(adresse))&&(controlVide(nom_c)));

if(test1)
  {
    bool test=C.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                                   QObject::tr("client ajouté.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_client->setModel(C.afficher());

 ui->cb_reff_modif->setModel(C.afficher_reference());
 ui->comboBox_refer_cf->setModel(CF.afficher_ref());
 ui->comboBoxidclient->setModel(CO1.afficher_idclient());
    }
    }
else
{ QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                           QObject::tr("client non ajouté, vérifier les champs.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pb_supprimer_client_clicked()
{
    QMessageBox msgBox;
    Clients C1;


C1.setRef(ui->cb_reff_modif->currentText().toInt());
        bool test=C1.supprimer(C1.getRef());
    if(test)
      {  msgBox.setText("supprission avec succes.");
    ui->tab_client->setModel(C1.afficher());
    ui->cb_reff_modif->setModel(C1.afficher_reference());
    ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    }else
    { msgBox.setText("Echec de supprission");}
        msgBox.exec();



}

void MainWindow::on_pb_modif_client_clicked()
{
    int telephone=ui->le_telephone_client->text().toInt();
    int Ref_c=ui->cb_reff_modif->currentText().toInt();
    QString Email=ui->le_Email_client->text();
    QString nom_c=ui->le_nom_client->text();
    QString pays=ui->le_pays_client->text();
    QString adresse=ui->le_adresse_client->text();
Clients C(Ref_c,telephone,Email,nom_c,pays,adresse);
bool test1=((controlEmail(Email))&&(controlRef(Ref_c))&&(controlTel(telephone))&&(controlVide(adresse))&&(controlVide(nom_c)));
if(test1)
  {
    bool test=C.modifier();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                                   QObject::tr("client modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_client->setModel(C.afficher());
 ui->comboBox_refer_cf->setModel(CF.afficher_ref());
 ui->cb_reff_modif->setModel(E.afficher_reference());
    }
    }
else
{ QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                           QObject::tr("client non ajouté, vérifier les champs.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

}



void MainWindow::on_pb_ajout_cf_clicked()
{
    int refer_clients=ui->comboBox_refer_cf->currentText().toInt();
 int numero=ui->le_num_cf->text().toInt();
 int points=ui->le_points_cf->text().toInt();
 int cheque=ui->le_cheque_cf->text().toInt();
 QDate date_em=ui->le_date_em->date();
 QDate date_ex=ui->le_date_ex->date();
 CarteFidelite CF(numero,points,cheque,date_em,date_ex,refer_clients);
 bool test1=((controlNumero(numero))&&(controlPoints(points))&&(controlCheque(cheque)));


     if(test1)
       {
         bool test=CF.ajouter();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("ajouter une carte fidélité"),
                                        QObject::tr("carte ajouté.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

      ui->tab_cf->setModel(CF.afficher());
      ui->comboBox_refer_cf->setModel(CF.afficher_ref());
      ui->cb_num_supp->setModel(CF.afficher_numero());
         }else{
             QMessageBox::critical(nullptr, QObject::tr("ajouter une carte fidélité"),
                                             QObject::tr("ce client posséde déjà une carte fidélité.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
         }
     else
     { QMessageBox::critical(nullptr, QObject::tr("ajouter une carte fidélité"),
                                QObject::tr("carte non ajouté, vérifier les champs.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_pb_supp_cf_clicked()
{
    CarteFidelite CF;
    CF.setNum(ui->cb_num_supp->currentText().toInt());
    bool test=CF.supprimer(CF.getNum());
    QMessageBox msgBox;
    if(test)
      {  msgBox.setText("supprission avec succes.");
    ui->tab_cf->setModel(CF.afficher());
    ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    ui->cb_num_supp->setModel(CF.afficher_numero());


    }else
    { msgBox.setText("Echec de supprission");}
        msgBox.exec();
}

void MainWindow::on_pb_modifier_cf_clicked()
{
    int refer_clients=ui->comboBox_refer_cf->currentText().toInt();
    int numero=ui->cb_num_supp->currentText().toInt();
    int points=ui->le_points_cf->text().toInt();
    int cheque=ui->le_cheque_cf->text().toInt();
    QDate date_em=ui->le_date_em->date();
    QDate date_ex=ui->le_date_ex->date();
    CarteFidelite CF(numero,points,cheque,date_em,date_ex,refer_clients);
    bool test1=((controlNumero(numero))&&(controlPoints(points))&&(controlCheque(cheque)));

    if(test1)
      {
       bool test=CF.modifier();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier une carte fidélité"),
                                       QObject::tr("carte modifié.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_cf->setModel(CF.afficher());
     ui->comboBox_refer_cf->setModel(CF.afficher_ref());

     ui->cb_num_supp->setModel(CF.afficher_numero());        }
        }
    else
    { QMessageBox::critical(nullptr, QObject::tr("modifier une carte fidélité"),
                               QObject::tr("carte non modifié, vérifier les champs.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_comboBox_tri_activated(const QString &arg1)
{
    QString choix=ui->comboBox_tri_cf->currentText();
    ui->tab_cf->setModel(CF.afficher_choix(choix));
}

void MainWindow::on_comboBox_tri_client_activated(const QString &arg1)
{
    QString choix=ui->comboBox_tri_client->currentText();
    ui->tab_client->setModel(E.afficher_choix(choix));

}

void MainWindow::on_pb_rech_cf_2_clicked()
{
    QString val=ui->dateEdit->text();
    if(val!="")
        ui->tab_cf->setModel(CF.afficher_recherche(val));
}

void MainWindow::on_search_pb_clicked()
{
    QString val=ui->le_amine->text();
    QString option=ui->cb_rech_client->currentText();
    if((val!="")&&(option=="nom"))
{        ui->tab_client->setModel(E.afficher_recherche(val));}
    else if((val!="")&&(option=="reference"))
    {
       ui->tab_client->setModel(E.afficher_recherche2(val));
    }
    else if((val!="")&&(option=="telephone"))
    {
       ui->tab_client->setModel(E.afficher_recherche3(val));
    }else if(option=="choisir")
    {
       ui->tab_client->setModel(E.afficher());
    }
}

void MainWindow::on_pb_rech_cf_3_clicked()
{
    QString option=ui->cb_rech_cf->currentText();
    QString val=ui->le_rech_cf->text();
    if((val!="")&&(option=="numero"))
    {
       ui->tab_cf->setModel(CF.afficher_recherche2(val));
    }else if((val!="")&&(option=="points"))
    {
       ui->tab_cf->setModel(CF.afficher_recherche3(val));
    }else if(option=="choisir")
        ui->tab_cf->setModel(CF.afficher());
}

void MainWindow::on_comboBox_tri_cf_activated(const QString &arg1)
{
    QString choix=ui->comboBox_tri_cf->currentText();
    ui->tab_cf->setModel(CF.afficher_choix(choix));
}

void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_pushButton_12_clicked()
{
    close();
}

void MainWindow::on_envoyerCmail_clicked()
{


    EnvoyerMail E;
        E.setModal(true);
        E.exec();


}

void MainWindow::on_ajouter_colis_clicked()
{
   int code= ui->code_barre->text().toInt();
   float largeur=ui->largeur->text().toFloat();
   float longeur=ui->longeur->text().toFloat();
   float poids=ui->poids->text().toFloat();
   float hauteur=ui->hauteur->text().toFloat();

colis CA(code,poids,longeur,largeur,hauteur);
QMessageBox msgBox;

if(CA.veriffloat(CA.gethauteur())==true&&CA.veriffloat(CA.getlongeur())==true&&CA.veriffloat(CA.getlargeur())==true&&CA.veriffloat(CA.getpoids())==true)
  { bool test=CA.ajouter();
    if(test==true)
    {msgBox.setText("Ajout avec succes.");
          ui->tabcolis->setModel(Cl1.afficher());
          ui->affectercolis->setModel(CC.afficher_idcolis());
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

void MainWindow::on_tabcolis_activated(const QModelIndex &index)
{
    QString val=ui->tabcolis->model()->data(index).toString();
   colis *CA;
    CA=Cl1.readColis(val);
    int code=CA->getcode_barre();

    float largeur=CA->getlargeur();
    float poids=CA->getpoids();
    float hauteur=CA->gethauteur();
    float longeur=CA->getlongeur();
    QString code_bare_s=QString::number(code);//à revenir
    QString poids_s=QString::number(poids, 'f', 4);
     QString longeur_s=QString::number(longeur, 'f', 4);
      QString largeur_s=QString::number(largeur, 'f', 4);
       QString hauteur_s=QString::number(hauteur, 'f', 4);
              ui->code_barre->setText(code_bare_s);
              ui->longeur->setText(longeur_s);
              ui->largeur->setText(largeur_s);
              ui->poids->setText(poids_s);
              ui->hauteur->setText(hauteur_s);

}

void MainWindow::on_modifier_colis_clicked()
{
    int code= ui->code_barre->text().toInt();
    float largeur=ui->largeur->text().toFloat();
    float longeur=ui->longeur->text().toFloat();
    float poids=ui->poids->text().toFloat();
    float hauteur=ui->hauteur->text().toFloat();

 colis CA(code,poids,longeur,largeur,hauteur);
 QMessageBox msgBox;

 if(CA.veriffloat(CA.gethauteur())==true&&CA.veriffloat(CA.getlongeur())==true&&CA.veriffloat(CA.getlargeur())==true&&CA.veriffloat(CA.getpoids())==true&&CA.verifierid(code))
   { bool test=CA.modifier();
     if(test==true)
     {msgBox.setText("Modification avec succes.");
           ui->tabcolis->setModel(Cl1.afficher());
          msgBox.exec();}
                  else {
                      msgBox.setText("Echec de modification");

                  }

     }
    else
    { msgBox.setText("Echec de modification ");
     }

 msgBox.exec();
}

void MainWindow::on_supprimer_colis_clicked()
{
    QMessageBox msgBox;
    int code=ui->code_barre->text().toUInt();
    QString numstring=ui->le_num->text();
    colis C;
    C.setcode_barre(code);
   bool test1=C.verifierid(C.getcode_barre());
   if(test1==true&&C.verifvidestring(ui->code_barre->text()))
     { C.supprimer(C.getcode_barre());
       msgBox.setText("Suppression avec succes.");

           ui->tabcolis->setModel(Cl1.afficher());

       }
       else
        {msgBox.setText("Echec de suppression");}
           msgBox.exec();
}

void MainWindow::on_chercher_colis_2_clicked()
{
    int choix;
       choix=ui->comboBox_colis->currentIndex();
       QString linechercher=ui->chercher_colis->text();
        qDebug()<<choix;
         qDebug()<<linechercher;
       ui->tabcolis->setModel(Cl1.chercher(choix,linechercher));

}

void MainWindow::on_pushButton_2_clicked()
{
    int choix2;
       choix2=ui->comboBox_tri->currentIndex();

       ui->tabcolis->setModel(Cl1.trierc(choix2));
}

void MainWindow::on_ajouter_etr_clicked()
{
    int ref= ui->ref->text().toInt();
    int nbs=ui->nsalles->text().toInt();
    int nbv=ui->nvehicules->text().toInt();
   QString adresse=ui->adresse->text();
   QString region=ui->region->text();

 Entrepots E1(ref,region,adresse,nbs,nbv);
 QMessageBox msgBox;

 if(E1.verifvide(E1.getadresse())==true&&E1.verifvide(E1.getregion())==true)
   { bool test=E1.ajouter();
     if(test==true)
     {msgBox.setText("Ajout avec succes.");
           ui->tabentrep->setModel(ET1.afficher());
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

void MainWindow::on_modifier_entr_clicked()
{
    int ref= ui->ref->text().toInt();
    int nbs=ui->nsalles->text().toInt();
    int nbv=ui->nvehicules->text().toInt();
   QString adresse=ui->adresse->text();
   QString region=ui->region->text();

 Entrepots E1(ref,region,adresse,nbs,nbv);
 QMessageBox msgBox;

 if(E1.verifvide(E1.getadresse())==true&&E1.verifvide(E1.getregion())==true&&E1.verifierref(ref))
   { bool test=E1.modifier();
     if(test==true)
     {msgBox.setText("Modification avec succes.");
           ui->tabentrep->setModel(ET1.afficher());
          msgBox.exec();}
                  else {
                      msgBox.setText("Echec de modification");

                  }

     }
    else
    { msgBox.setText("Echec de modification ");
     }
}

void MainWindow::on_supprimer_entro_clicked()
{
    QMessageBox msgBox;
    int ref= ui->ref->text().toInt();
    QString refs=ui->ref->text();
    Entrepots E12;
    E12.setref(ref);
   bool test1=E12.verifierref(ref);
   if(test1==true&&E12.verifierref(ref))
     { E12.supprimer(E12.getref());
       msgBox.setText("Suppression avec succes.");

         ui->tabentrep->setModel(ET1.afficher());

       }
       else
        {msgBox.setText("Echec de suppression");}
           msgBox.exec();

}

void MainWindow::on_trier_entr_clicked()
{
    int choix2;
       choix2=ui->comboBox_tri22->currentIndex();

       ui->tabentrep->setModel(ET1.trierc(choix2));
}

void MainWindow::on_chercher_entr_clicked()
{
    int choix;
       choix=ui->comboBox_entro->currentIndex();
       QString linechercher=ui->lineEditentre->text();
        qDebug()<<choix;
         qDebug()<<linechercher;
       ui->tabentrep->setModel(ET1.chercher(choix,linechercher));
}

void MainWindow::on_tabentrep_activated(const QModelIndex &index)
{
    QString val=ui->tabentrep->model()->data(index).toString();
  Entrepots *CA;
    CA=ET1.readEntrepots(val);
    int ref=CA->getref();

    int nsalles=CA->getnsalles();
   int nvehicules=CA->getnvehicules();
    QString nsalles_s=QString::number(nsalles);
      QString nv_s=QString::number(nvehicules);
        QString ref_s=QString::number(ref);
              ui->ref->setText(ref_s);
              ui->nsalles->setText(nsalles_s);
              ui->nvehicules->setText(nv_s);
              ui->adresse->setText(CA->getadresse());
              ui->region->setText(CA->getregion());
}

void MainWindow::on_pushButton_3_clicked()
{
    EnvoyerMail E;
    E.setModal(true);
    E.exec();
}

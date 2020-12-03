#include "gestionclient.h"
#include "ui_gestionclient.h"
#include <QtDebug>
#include <QDebug>




Gestionclient::Gestionclient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestionclient)
{
    ui->setupUi(this);

    ui->le_telephone->setValidator(new QIntValidator(10000000, 99999999, this));
    ui->le_tel_modif->setValidator(new QIntValidator(10000000, 99999999, this));
    ui->le_cheque->setValidator(new QIntValidator(100000, 999999, this));
    ui->le_cheque_modif->setValidator(new QIntValidator(100000, 999999, this));
    ui->le_num->setValidator(new QIntValidator(1000, 9999, this));

    ui->cb_num_modif->setModel(CF.afficher_numero());
    ui->cb_num_supp->setModel(CF.afficher_numero());
    ui->le_ref->setValidator(new QIntValidator(10000, 99999, this));


    ui->le_points->setValidator(new QIntValidator(100, 999, this));
    ui->le_points_modif->setValidator(new QIntValidator(100, 999, this));
    ui->tab_client->setModel(E.afficher());
    ui->tab_cf->setModel(CF.afficher());
    ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    ui->cb_reff_supp->setModel(E.afficher_reference());
    ui->cb_reff_modif->setModel(E.afficher_reference());

    //music
    player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::positionChanged,this,&Gestionclient::on_positionChanged);


}



void Gestionclient::on_pushButton_11_clicked()
{
    close();
}

void Gestionclient::on_pushButton_5_clicked()
{
    close();
}

void Gestionclient::on_pushButton_10_clicked()
{
    close();
}
void Gestionclient::on_pushButton_12_clicked()
{
 close();
}

void Gestionclient::on_pushButton_19_clicked()
{
    close();
}

void Gestionclient::on_pushButton_22_clicked()
{
    close();
}

void Gestionclient::on_pushButton_8_clicked()
{
    Envoyermail E;
    E.setModal(true);
    E.exec();

}
void Gestionclient::on_pushButton_ajout_clicked()
{



    int telephone=ui->le_telephone->text().toInt();
    int Ref_c=ui->le_ref->text().toInt();
    QString Email=ui->le_Email->text();
    QString nom_c=ui->le_nom->text();
    QString pays=ui->le_pays->text();
    QString adresse=ui->le_adresse->text();
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
 ui->cb_reff_supp->setModel(C.afficher_reference());
 ui->cb_reff_modif->setModel(C.afficher_reference());
 ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    }
    }
else
{ QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                           QObject::tr("client non ajouté, vérifier les champs.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void Gestionclient::on_pb_supprimer_clicked()
{
    QMessageBox msgBox;
    Clients C1;


C1.setRef(ui->cb_reff_supp->currentText().toInt());
        bool test=C1.supprimer(C1.getRef());
    if(test)
      {  msgBox.setText("supprission avec succes.");
    ui->tab_client->setModel(C1.afficher());
    ui->cb_reff_supp->setModel(C1.afficher_reference());
    ui->cb_reff_modif->setModel(C1.afficher_reference());
    ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    }else
    { msgBox.setText("Echec de supprission");}
        msgBox.exec();



}
void Gestionclient::on_pushButton_2_clicked()
{
    int telephone=ui->le_tel_modif->text().toInt();
    int Ref_c=ui->cb_reff_modif->currentText().toInt();
    QString Email=ui->le_email_modif->text();
    QString nom_c=ui->le_nom_modif->text();
    QString pays=ui->le_pays_modif->text();
    QString adresse=ui->le_adresse_modif->text();
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
void Gestionclient::on_pb_ajout_cf_clicked()
{
    int refer_clients=ui->comboBox_refer_cf->currentText().toInt();
 int numero=ui->le_num->text().toInt();
 int points=ui->le_points->text().toInt();
 int cheque=ui->le_cheque->text().toInt();
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
      ui->cb_num_modif->setModel(CF.afficher_numero());
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

void Gestionclient::on_pb_supp_cf_clicked()
{
    CarteFidelite CF;
    CF.setNum(ui->cb_num_supp->currentText().toInt());
    bool test=CF.supprimer(CF.getNum());
    QMessageBox msgBox;
    if(test)
      {  msgBox.setText("supprission avec succes.");
    ui->tab_cf->setModel(CF.afficher());
    ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    ui->comboBox_refer_cf->setModel(CF.afficher_ref());
    ui->cb_num_modif->setModel(CF.afficher_numero());
    ui->cb_num_supp->setModel(CF.afficher_numero());


    }else
    { msgBox.setText("Echec de supprission");}
        msgBox.exec();
}

void Gestionclient::on_pb_modifier_cf_clicked()
{
    int refer_clients=ui->comboBox_refer_cf->currentText().toInt();
    int numero=ui->cb_num_modif->currentText().toInt();
    int points=ui->le_points_modif->text().toInt();
    int cheque=ui->le_cheque_modif->text().toInt();
    QDate date_em=ui->le_date_em_modif->date();
    QDate date_ex=ui->le_date_ex_modif->date();
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
     ui->cb_num_modif->setModel(CF.afficher_numero());
     ui->cb_num_supp->setModel(CF.afficher_numero());        }
        }
    else
    { QMessageBox::critical(nullptr, QObject::tr("modifier une carte fidélité"),
                               QObject::tr("carte non modifié, vérifier les champs.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }

}



void Gestionclient::on_comboBox_tri_activated(const QString &arg1)
{
    QString choix=ui->comboBox_tri->currentText();
    ui->tab_cf->setModel(CF.afficher_choix(choix));
}

void Gestionclient::on_comboBox_tri_2_activated(const QString &arg1)
{
    QString choix=ui->comboBox_tri_2->currentText();
    ui->tab_client->setModel(E.afficher_choix(choix));
}


void Gestionclient::on_pb_rech_cf_2_clicked()
{
    QString val=ui->dateEdit->text();
    if(val!="")
        ui->tab_cf->setModel(CF.afficher_recherche(val));
}

void Gestionclient::on_search_pb_clicked()
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

void Gestionclient::on_pb_rech_cf_3_clicked()
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





//control de saisie:

bool Gestionclient::controlTel(int test)
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
bool Gestionclient::controlRef(int test)
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
bool Gestionclient::controlVide(QString test)
{
    if(test!="")
        return  true;
    return false;
}
bool Gestionclient::controlEmail(QString test)
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
bool Gestionclient:: controlNumero(int test)
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
bool Gestionclient::controlPoints(int test)
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
bool Gestionclient:: controlCheque(int test)
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
Gestionclient::~Gestionclient()
{
    delete ui;
    delete player;

}














void Gestionclient::on_slider_volume_sliderMoved(int position)
{
    player->setVolume(position);
}

void Gestionclient::on_start_clicked()
{
    //load the file
    player->setMedia(QUrl::fromLocalFile("C:/Users/Amine/Documents/projetcpp/music.mp3"));
    player->play();
    qDebug()<< player->errorString();
}

void Gestionclient::on_pause_clicked()
{
    player->stop();
}


void Gestionclient::on_positionChanged(qint64 position)
{
    ui->slider_volume->setMaximum(position);
}

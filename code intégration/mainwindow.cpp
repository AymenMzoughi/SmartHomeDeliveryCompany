#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->stackedWidget1->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;

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
    /*ui->pushButtonclients->setDisabled(true);
    ui->pushButtonsav->setDisabled(true);
    ui->pushButtonstock->setDisabled(true);
    ui->Commande->setDisabled(true);
    ui->pushButtonclients->setDisabled(true);*/

}

void MainWindow::on_pushButtonclients_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
    /*ui->pushButtonsav->setDisabled(true);
    ui->pushButtonemployees->setDisabled(true);
    ui->pushButtonstock->setDisabled(true);
    ui->Commande->setDisabled(true);*/

}

void MainWindow::on_pushButtonstock_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(5);
    /*ui->pushButtonclients->setDisabled(true);
    ui->pushButtonemployees->setDisabled(true);
    ui->pushButtonsav->setDisabled(true);
    ui->Commande->setDisabled(true);
    ui->pushButtonclients->setDisabled(true);*/

}

void MainWindow::on_pushButtonsav_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
    /*ui->pushButtonclients->setDisabled(true);
    ui->pushButtonemployees->setDisabled(true);
    ui->pushButtonstock->setDisabled(true);
    ui->Commande->setDisabled(true);
    ui->pushButtonclients->setDisabled(true);*/

}

void MainWindow::on_pageacc_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    /*ui->pushButtonclients->setDisabled(false);
    ui->pushButtonemployees->setDisabled(false);
    ui->pushButtonstock->setDisabled(false);
    ui->Commande->setDisabled(false);
    ui->pushButtonclients->setDisabled(false);
     ui->pushButtonsav->setDisabled(false);*/

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

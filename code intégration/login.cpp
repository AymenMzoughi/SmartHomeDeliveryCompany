#include "login.h"
#include "ui_login.h"
#include "ui_mainwindow.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
    delete M;
    //delete oi;

}

/*void Login::on_pb_clear_clicked()
{
    ui->le_password->setText("");
    ui->le_username->setText("");
}

void Login::on_pb_login_clicked()
{
    QString RecupRole;
    QString Username, Password , role;
   Username =ui->le_username->text();
    Password=ui->le_password->text();
 Admin A1(Username,Password,role);
 ui->role->setText(A1.afficherRole());
 QString RecupRole=ui->role->text();
 qDebug()<<RecupRole;
 bool test=A1.Login();


 if(test)
   {
     ui->role->setText(A1.afficherRole());
     RecupRole=ui->role->text();
     ui->label_3->setText("[+]Valid username and password ");



    }
 else {
       ui->label_3->setText("wrong username or password");
      }

 if(RecupRole=="admin")
 {


 }else if(RecupRole=="userstock")
 {
     QThread::sleep(3);//attendre 3 secondes avant fermer la fenetre
     close();
     M= new MainWindow(this);
     M->show();

 }





}*/


void Login::on_pushButton_clicked()
{
    MainWindow amine;

}

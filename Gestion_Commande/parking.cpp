#include "parking.h"
#include "ui_parking.h"

Parking::Parking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parking)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
}

Parking::~Parking()
{
    delete ui;
}
void Parking::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
    {numdesv++;
     numplace--;
    QString numv_string=QString::number(numdesv);
    QString nump_string=QString::number(numplace);
        ui->le_ve->setText(numv_string);
      ui->le_pd->setText(nump_string);}// si les données reçues de arduino via la liaison série sont égales à 1*/
}

void Parking::on_pushButton_clicked()
{

}

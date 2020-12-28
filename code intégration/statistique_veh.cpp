#include "statistique_veh.h"
#include "ui_statistique_veh.h"

Statistique_veh::Statistique_veh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique_veh)
{
    ui->setupUi(this);
}

Statistique_veh::~Statistique_veh()
{
    delete ui;
}

void Statistique_veh::paintEvent(QPaintEvent *)
{
    int A=V1.statistique1();
    int B=V1.statistique2();
    int C=V1.statistique3();

    float s1= A*100 ;
           float s2=B*100;
           float nb = A+B+C;
           float q2 ;
           q2 = s1/nb ;
           float q3;
           q3=s2/nb;
           float y  ;
           y = (q2*360)/100 ;
           float m;
           m= (q3*360)/100;
           float z  ;
           z=360-(y+m) ;
       QPainter painter(this);
       QRectF size=QRectF(10,10,this->width()-100,this->width()-100);
       painter.setBrush(Qt::blue);

       painter.drawPie(size,0,16*y);
       painter.setBrush(Qt::green);
       painter.drawPie(size,16*y,16*m);
       painter.setBrush(Qt::darkYellow);
       painter.drawPie(size,16*(m+y),16*z);

    update();
}

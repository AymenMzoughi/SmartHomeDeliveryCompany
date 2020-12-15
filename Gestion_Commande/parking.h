#ifndef PARKING_H
#define PARKING_H

#include <QDialog>
#include"arduino.h"
namespace Ui {
class Parking;
}

class Parking : public QDialog
{
    Q_OBJECT

public:
    explicit Parking(QWidget *parent = nullptr);
    ~Parking();

private slots:
    void on_pushButton_clicked();
   void  update_label();

private:
    Ui::Parking *ui;
    Arduino A;
    QByteArray data;
    int numdesv=0;
    int numplace=30;
};

#endif // PARKING_H

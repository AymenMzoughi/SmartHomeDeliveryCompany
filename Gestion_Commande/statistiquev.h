#ifndef STATISTIQUEV_H
#define STATISTIQUEV_H
#include"vehiculewin.h"
#include"vehicule.h"
#include"gestionCommande.h"
#include <QWidget>

class statistiquev : public QWidget
{
    Q_OBJECT
public:
    explicit statistiquev(QWidget *parent = nullptr);
protected:
   void paintEvent(QPaintEvent *);
signals:
private:
   Ui:: gestionCommande*ui;
   Vehicule V1;
};

#endif // STATISTIQUEV_H

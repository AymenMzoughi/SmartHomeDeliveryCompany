#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include"vehicule.h"
#include <QWidget>

class statistique : public QWidget
{
    Q_OBJECT
public:
    explicit statistique(QWidget *parent = nullptr);
protected:
   void paintEvent(QPaintEvent *);
signals:
private:
   Vehicule V2;
};

#endif // STATISTIQUE_H

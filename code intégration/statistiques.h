#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include <QWidget>
#include"vehicule.h"
#include"mainwindow.h"
class statistiques : public QWidget
{
    Q_OBJECT
public:
    explicit statistiques(QWidget *parent = nullptr);
protected:
  void paintEvent(QPaintEvent *);
signals:
private:
    Vehicule V1;
};

#endif // STATISTIQUES_H

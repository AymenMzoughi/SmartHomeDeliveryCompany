#ifndef STATISTIQUE_VEH_H
#define STATISTIQUE_VEH_H

#include <QDialog>
#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
#include"vehicule.h"
namespace Ui {
class Statistique_veh;
class QPieSlice;
}

class Statistique_veh : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique_veh(QWidget *parent = nullptr);
    ~Statistique_veh();
    void paintEvent(QPaintEvent *) ;

private:
    Ui::Statistique_veh *ui;
    Vehicule V1;
};

#endif // STATISTIQUE_VEH_H

#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H
#include "envoyermail.h"
#include "clients.h"
#include "cartefidelite.h"
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QDate>
#include <QMainWindow>
#include <QMediaPlayer>






QT_BEGIN_NAMESPACE
namespace Ui { class Gestionclient; }
QT_END_NAMESPACE

class Gestionclient : public QMainWindow
{
    Q_OBJECT

public:
    Gestionclient(QWidget *parent = nullptr);
    ~Gestionclient();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_ajout_clicked();



    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_pb_ajout_cf_clicked();

    void on_pb_supp_cf_clicked();

    void on_pb_modifier_cf_clicked();

    void on_comboBox_tri_activated(const QString &arg1);

    void on_comboBox_tri_2_activated(const QString &arg1);

    void on_pb_rech_cf_2_clicked();

   void on_search_pb_clicked();

    void on_pb_rech_cf_3_clicked();
    bool controlTel(int test);
    bool controlRef(int test);
    bool controlVide(QString test);
    bool controlEmail(QString test);
    bool controlNumero(int test);
    bool controlPoints(int test);
    bool controlCheque(int test);









    void on_slider_volume_sliderMoved(int position);

    void on_start_clicked();

    void on_pause_clicked();

    void on_positionChanged(qint64 position);




private:
    Ui::Gestionclient *ui;
    Clients E;
    CarteFidelite CF;
    QMediaPlayer* player;



};
#endif // GESTIONCLIENT_H

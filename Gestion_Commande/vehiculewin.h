#ifndef VEHICULEWIN_H
#define VEHICULEWIN_H

#include <QDialog>
#include"vehicule.h"
namespace Ui {
class Vehiculewin;
}

class Vehiculewin : public QDialog
{
    Q_OBJECT

public:
    explicit Vehiculewin(QWidget *parent = nullptr);
    ~Vehiculewin();

private slots:
    void on_Ajouter_clicked();

    void on_supprimer_2_clicked();

    void on_Modifier_clicked();

    void on_chercherv_clicked();

private:
    Ui::Vehiculewin *ui;
    Vehicule V1;
};

#endif // VEHICULEWIN_H

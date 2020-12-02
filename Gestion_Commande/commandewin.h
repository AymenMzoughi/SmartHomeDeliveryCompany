#ifndef COMMANDEWIN_H
#define COMMANDEWIN_H

#include <QMainWindow>
#include<QPrinter>
#include<QPrintDialog>
#include<QDialog>
#include"commande.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Commandewin; }
QT_END_NAMESPACE

class Commandewin : public QMainWindow
{
    Q_OBJECT

public:
    Commandewin(QWidget *parent = nullptr);
    ~Commandewin();

private slots:

    void on_supprimer_clicked();

    void on_ajouter_clicked();
    void on_Modifier_clicked();

    void on_chercher_2_clicked();
  void on_imprimer_clicked();

  void on_pushButton_clicked();

private:
    Ui::Commandewin *ui;
    Commande C1;
};
#endif // COMMANDEWIN_H

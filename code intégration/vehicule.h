#ifndef VEHICULE_H
#define VEHICULE_H
#include<QSqlQueryModel>
#include<QString>
#include<QtWidgets>
class Vehicule
{
public:
    Vehicule();
    Vehicule(QString,QString,QString,QString,QString,QString,QString);
    QString getmatricule();
    QString getnumdechassis();
    QString getmarque();
    QString gettypev();
    QString gettypecarburant();
    QString getdatecirculation();
   QString getidemp();
    void setmatricule(QString);
    void setnumdechassis(QString);
    void setmarque(QString);
    void settypecarburant(QString);
    void setdatecirculation(QString);
    void settypev(QString tv);
    void setidemp(QString emp);
   bool ajouter();
   bool modifier();
QSqlQueryModel* afficher();
bool supprimer(QString);
QSqlQueryModel* chercher(int,QString);
bool verif(QString);
bool verifvidestring(QString);
int statistique1();
int statistique2();
int statistique3();
bool verifvide(QString);
QSqlQueryModel* affiche_employer();
bool verifierMatricule(QString);
bool verifint(QString S);
bool verifchassis(QString);
Vehicule*readvehicule(QString);
private:
  QString matricule,numdechassis,marque,typev,typecarburant,datecirculation,idemp;


};

#endif // VEHICULE_H

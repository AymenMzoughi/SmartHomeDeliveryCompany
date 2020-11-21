#ifndef VEHICULE_H
#define VEHICULE_H
#include<QSqlQueryModel>
#include<QString>
class Vehicule
{
public:
    Vehicule();
    Vehicule(QString,QString,QString,QString,QString,QString,int);
    QString getmatricule();
    QString getnumdechassis();
    QString getmarque();
    QString gettypev();
    QString gettypecarburant();
    QString getdatecirculation();
    int getidemp();
    void setmatricule(QString);
    void setnumdechassis(QString);
    void setmarque(QString);
    void settypecarburant(QString);
    void setdatecirculation(QString);
   bool ajouter();
   bool modifier();
QSqlQueryModel* afficher();
bool supprimer(QString);
private:
  QString matricule,numdechassis,marque,typev,typecarburant,datecirculation;
  int idemp;

};

#endif // VEHICULE_H

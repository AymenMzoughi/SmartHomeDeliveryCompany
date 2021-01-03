#ifndef ENTREPOTS_H
#define ENTREPOTS_H
#include<QSqlQueryModel>
#include<QString>
#include<QtWidgets>
class Entrepots
{
public:
    Entrepots();
    Entrepots(int,QString,QString,int,int);
    int getref();
    QString getregion();
    QString getadresse();
    int getnsalles();
    int getnvehicules();

    void setref(int);
    void setregion(QString);
    void setadresse(QString);
    void setnsalles(int);
    void setnvehicules(int);
    //void settypev(QString tv);
    //void setidemp(QString emp);
   bool ajouter();
   bool modifier();
QSqlQueryModel* afficher();
bool supprimer(int);// avec la ref
QSqlQueryModel* chercher(int,QString);// ref , adresse
bool verif(QString);// à revenir
bool verifvidestring(QString);// à revenir

bool verifvide(QString);// à revenir
QSqlQueryModel* affiche_entrepots();
bool verifierref(int);
bool verifiregion(QString S);
bool verifadresse(QString);
Entrepots*readEntrepots(QString);
QSqlQueryModel* trierc(int);
private:
  QString adresse,region ;//,marque,typev,typecarburant,datecirculation,idemp;
  int ref,nsalles,nvehicules;

};


#endif // ENTREPOTS_H

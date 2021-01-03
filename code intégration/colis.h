#ifndef COLIS_H
#define COLIS_H

#include<QString>
#include<QSqlQueryModel>
class colis
{
public:
    colis();
    colis(int,float,float,float,float);
    bool verifvidestring(QString); //à revenir
    bool verifint(int);            // à revenir
    bool veriffloat(float);        // à revenir
    int getcode_barre();
    void setcode_barre(int);
    float getpoids();
    void setpoids(float);
    float getlongeur();
    void setlongeur(float);
    float getlargeur();
    void setlargeur(float);
    float gethauteur();
    void sethauteur(float);
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* chercher(int,QString);
    bool verifierid(int);
    QSqlQueryModel *afficher_idclient();// à revenir
    QSqlQueryModel *afficher_idemp();  // à revenir
    colis* readColis( QString val);
    QSqlQueryModel* trierc(int);


private :
int code_barre;
float poids,longeur,largeur,hauteur;

};

#endif // COLIS_H

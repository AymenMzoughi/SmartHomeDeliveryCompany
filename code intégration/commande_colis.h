#ifndef COMMANDE_COLIS_H
#define COMMANDE_COLIS_H
#include<QString>
#include<QSqlQueryModel>
class Commande_colis
{
public:
    Commande_colis();
    Commande_colis(int,int,QString);
     QSqlQueryModel *afficher_idcommande();
     QSqlQueryModel *afficher_idcolis();
     QSqlQueryModel *afficher_tab(int);
     bool affecteruncolis();
     bool verifvidestring(QString S);
     bool updateetat(int);
     bool verifiercommandeaff(int);
   int verifiercolis(int);
     int verifcommandeidclient(int);

private:
    int numeroc,id_colis;
    QString etat;
};

#endif // COMMANDE_COLIS_H

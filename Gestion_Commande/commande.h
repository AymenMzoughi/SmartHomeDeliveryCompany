#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQueryModel>
class Commande
{
public:
    Commande();
    Commande(int,QString,QString,QString,QString,float,int);
    int getnum();
    int getidclient();
    QString getdescription();
    int getcode_colis();
    QString getadresse();
    QString getdatecommande();
    QString getmodepaiment();
    float getmontant();
    void setdescription(QString);
    void setadresse(QString);
    void setdatecommande(QString);
    void setmodepaiment(QString);
    void setmontant(float);
    void setnum(int);
    void setidclient(int);
    void setcodesclient(int);
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* chercher(int,QString);
private :
int num;
int idclient;
QString description,adresse,datedecommande,modepaiment;
float montant;
};

#endif // COMMANDE_H

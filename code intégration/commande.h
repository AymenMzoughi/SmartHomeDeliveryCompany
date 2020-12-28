#ifndef COMMANDE_H
#define COMMANDE_H

#include<QString>
#include<QSqlQueryModel>
class Commande
{
public:
    Commande();
    Commande(int,QString,QString,QString,float,int,QString);
    bool verifvidestring(QString);
    bool verifint(int);
    bool veriffloat(float);
    int getnum();
    int getidclient();
    QString getidemp();
    void setidemp(QString);
    QString getdescription();
    int getcode_colis();
    QString getdatecommande();
    QString getmodepaiment();
    float getmontant();
    void setdescription(QString);
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
    bool verifierid(int);
    QSqlQueryModel *afficher_idclient();
    QSqlQueryModel *afficher_idemp();
    Commande* readcommande( QString val);

private :
int num;
int idclient;
QString description,datedecommande,modepaiment,idemp;
float montant;
};

#endif // COMMANDE_H

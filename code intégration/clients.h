#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include <QSqlQueryModel>
#include <QObject>
#include <QDebug>
#include <QSqlQuery>
class Clients
{
public:
    Clients();
    Clients(int,int,QString,QString,QString,QString);
    int getRef();
    int getTel();
    QString getEmail();
    QString getnom();
    QString getPays();
    QString getadr();
    void setRef(int);
    void setTel(int);
    void setEmail(QString);
    void setNom(QString);
    void setPays(QString);
    void setadr(QString);

    bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
bool modifier();
QSqlQueryModel * afficher_choix(QString);
QSqlQueryModel * afficher_recherche(QString);
QSqlQueryModel * afficher_recherche2(QString);
QSqlQueryModel * afficher_recherche3(QString);
QSqlQueryModel * afficher_reference();
 ~Clients();
private:
    int Ref_c;
    int telephone;
    QString Email,nom_c,pays,adresse;
};

#endif // CLIENTS_H

#ifndef CARTEFIDELITE_H
#define CARTEFIDELITE_H
#include<qdatetime.h>
#include <QString>
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QSqlQuery>
#include <QDate>
#include <QDebug>
#include "clients.h"
class CarteFidelite
{
private:
int numero,points,cheque;
QDate date_em,date_ex;
int refer_clients;


public:
    CarteFidelite();
    CarteFidelite(int,int,int,QDate,QDate,int);
    int getNum();
    int getPoints();
   int getCheque();
QDate getDateEm();
QDate getDateEx();
int getReferCF(){return refer_clients;}
void setNum(int);
void setPoints(int);
void setCheque(int);
void setDateEm(QDate);
void setDateEx(QDate);
bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
bool modifier();
QSqlQueryModel * afficher_choix(QString);
QSqlQueryModel * afficher_recherche(QString);
QSqlQueryModel * afficher_recherche2(QString);
QSqlQueryModel * afficher_recherche3(QString);
QSqlQueryModel * afficher_ref();
QSqlQueryModel * afficher_numero();
};

#endif // CARTEFIDELITE_H

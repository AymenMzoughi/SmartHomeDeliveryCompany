#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Conge
{
public:
Conge();

  Conge(int,QString,QString,QString,QString,int,QString,int);
  int getidc();
  int getidemp();
  QString getnom();
  QString getprenom();
  QString getdatedeb();
  QString getdatefin();
  QString getetat();
  int getduree();
  void setnom(QString);
  void setprenom(QString);
  void setdatedeb(QString);
  void setdatefin(QString);
  void setetat(QString);
  void setidc(int);
  void setidemp(int);
  void setduree(int);
  bool ajouterc();
  bool supprimerc(int);
  bool modifierc();

  QSqlQueryModel* afficherc();
  QSqlQueryModel* afficherE();
  QSqlQueryModel* chercherc(int,QString);
  QSqlQueryModel* trierc(int);

  Conge* readconge (QString val);
  int verifid(int);

private:
  QString nom,prenom,datedeb,datefin,etat;
  int idc,idemp,duree;
};

#endif // CONGE_H

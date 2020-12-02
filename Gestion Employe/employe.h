#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

  class Employe
{
    public:
    Employe();

      Employe(int,QString,QString,QString,int,QString,QString);
      int getidemp();
      QString getnom();
      QString getprenom();
      QString getdate();
      int getnumtel();
      QString getadr();
      QString getmail();
      void setnom(QString);
      void setprenom(QString);
      void setadr(QString);
      void setmail(QString);
      void setdate(QString);
      void setidemp(int);
      void setnumtel(int);

      bool ajouter();
      bool supprimer(int);
      bool modifier();
      QSqlQueryModel* afficher();
      QSqlQueryModel* chercher(int,QString);

  private:
      QString nom,prenom,date,adr,mail;
      int idemp,numtel;

  };



#endif // EMPLOYE_H








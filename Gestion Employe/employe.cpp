#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
#include <QMessageBox>
#include <QVBoxLayout>

Employe::Employe()
{
    idemp=0;
    nom="";
    prenom="";
    date="";
    numtel=0;
    adr="";
    mail="";

}
Employe::Employe(int idemp,QString nom,QString prenom,QString date,int numtel,QString adr,QString mail)
{
    this->idemp=idemp;
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->numtel=numtel;
    this->adr=adr;
    this->mail=mail;
}
int Employe::getidemp()
{
    return idemp;
}
int Employe:: getnumtel()
{
    return numtel;
}
QString Employe:: getnom()
{
    return nom;
}
QString Employe:: getprenom()
{
    return prenom;
}

QString Employe:: getdate()
{
    return date;
}

QString Employe:: getadr()
{
    return adr;
}

QString Employe:: getmail()
{
    return mail;
}
void Employe ::setnom(QString n)
{
    nom=n;
}
void Employe ::setprenom(QString p)
{
    prenom=p;
}
void Employe::setdate(QString dns)
{
    date=dns;

}
void Employe ::setadr(QString a)
{
    adr=a;
}
void Employe :: setmail(QString m)
{
    mail=m;
}
void Employe :: setidemp(int id)
{
    idemp=id;
}
void Employe::setnumtel(int nt)
{
    numtel=nt;
}
bool Employe :: ajouter()
{
    QSqlQuery query;
    QString idemp_string=QString::number(idemp);
    QString numtel_string=QString::number(numtel);
    QDate date_date =QDate::fromString(date,"dd/MM/yy");
          query.prepare("INSERT INTO EMPLOYE (IDEMP,NOM,PRENOM,DATEN,NUMTEL,ADR,MAIL) "
                        "VALUES (:IDEMP,:NOM,:PRENOM,:DATEN,:NUMTEL,:ADR,:MAIL)");
          query.bindValue(":IDEMP", idemp_string);
          query.bindValue(":NOM",nom);
          query.bindValue(":PRENOM",prenom);
          query.bindValue(":DATEN",date_date);
          query.bindValue(":NUMTEL",numtel_string);
          query.bindValue(":ADR",adr);
          query.bindValue(":MAIL",mail);

          return query.exec();

}
bool Employe ::modifier()
{
    QSqlQuery query;
    QString idemp_string=QString::number(idemp);
    QString numtel_string=QString::number(numtel);
    QDate date_date =QDate::fromString(date,"dd/MM/yy");
   query.prepare(" UPDATE EMPLOYE SET NOM=:NOM,PRENOM=:PRENOM,DATEN=:DATEN,NUMTEL=:NUMTEL,ADR=:ADR,MAIL=:MAIL WHERE IDEMP=:IDEMP");
   query.bindValue(":IDEMP", idemp_string);
   query.bindValue(":NOM",nom);
   query.bindValue(":PRENOM",prenom);
   query.bindValue(":DATEN",date_date);
   query.bindValue(":NUMTEL",numtel_string);
   query.bindValue(":ADR",adr);
   query.bindValue(":MAIL",mail);
   return query.exec();

}

QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM EMPLOYE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEMP"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEN"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADR"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("MAIL"));

    return model;


}
bool Employe::supprimer(int idemp)
{           QSqlQuery query;
            query.prepare(" Delete from EMPLOYE where IDEMP=:IDEMP");
            query.bindValue(0,idemp);
           return query.exec();


}


QSqlQueryModel* Employe::chercher(int index,QString text)
{
QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(index==0)
   { query.prepare("SELECT * FROM EMPLOYE where IDEMP like '"+text+"'");
     query.exec();
     model->setQuery(query);
    }

   if(index==1)
      {
       query.prepare("SELECT * FROM EMPLOYE where NOM like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==2)
      {
       query.prepare("SELECT * FROM EMPLOYE where NUMTEL like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }

    return model;

}

Employe* Employe::reademploye (QString val)
{
 QSqlQuery query;
    query.prepare("Select * FROM EMPLOYE where IDEMP='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {  qDebug()<<"test"<<val;
               setidemp(query.value(0).toInt());
              setnom(query.value(1).toString());
             setprenom(query.value(2).toString());
             setdate(query.value(3).toString());
              setnumtel(query.value(4).toInt());
             setadr(query.value(5).toString());
             setmail(query.value(6).toString());

            }
        }
     return this;
}
bool Employe::controlemail(QString test)
{

    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@' )
        {
            return true;
        }
    }
   {

    return false;
}}
 bool Employe::verifid(int idemp)
 {bool test=false;
      QSqlQuery  query;
      QString num_string=QString::number(idemp);
             query.prepare("SELECT * FROM EMPLOYE where IDEMP=:idemp");
              query.bindValue(":idemp",num_string);
         if(query.exec()&&query.next())
         {     test=true;
              return test;
         }
         return test;



 }

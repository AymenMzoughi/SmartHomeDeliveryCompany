#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>

employe::employe()
{
    idemp=0;
    numtel=0;
    nom="";
    prenom="";
    adr="";
    mail="";
    date="";
}
employe::employe(int idemp,QString nom,QString prenom,QString date,int numtel,QString adr,QString mail)
{
    this->idemp=idemp;
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->numtel=numtel;
    this->adr=adr;
    this->mail=mail;
}
int employe::getidemp()
{
    return idemp;
}
int employe:: getnumtel()
{
    return numtel;
}
QString employe:: getnom()
{
    return nom;
}
QString employe:: getprenom()
{
    return prenom;
}

QString employe:: getdate()
{
    return date;
}

QString employe:: getadr()
{
    return adr;
}

QString employe:: getmail()
{
    return mail;
}
void employe ::setnom(QString n)
{
    nom=n;
}
void employe ::setprenom(QString p)
{
    prenom=p;
}
void employe::setdate(QString dns)
{
    date=dns;

}
void employe ::setadr(QString a)
{
    adr=a;
}
void employe :: setmail(QString m)
{
    mail=m;
}
void employe :: setidemp(int id)
{
    idemp=id;
}
void employe::setnumtel(int nt)
{
    numtel=nt;
}
bool employe :: ajouter()
{
    QSqlQuery query;
    QString idemp_string=QString::number(idemp);
    QString numtel_string=QString::number(numtel);
    QDate date_date =QDate::fromString(date,"dd/MM/yy");
          query.prepare("INSERT INTO COMMANDE (IDEMP,NOM,PRENOM,DATEDENAISSANCE,NUMEROTEL,ADRESSE,EMAIL) "
                        "VALUES (:IDEMP,:NOM,:PRENOM,:DATEDENAISSANCE,:NUMEROTEL,:ADRESSE,:EMAIL)");
          query.bindValue(":IDEMP", idemp_string);
          query.bindValue(":NOM",nom);
          query.bindValue(":PRENOM",prenom);
             query.bindValue(":DATEDENAISSANCE",date_date);
          query.bindValue(":NUMEROTEL",numtel_string);
          query.bindValue(":ADRESSE",adr);
          query.bindValue(":EMAIL",mail);
          return query.exec();

}
bool employe ::modifier()
{
    QSqlQuery query;
    QString idemp_string=QString::number(idemp);
    QString numtel_string=QString::number(numtel);
    QDate date_date =QDate::fromString(date,"dd/MM/yy");
   query.prepare(" UPDATE COMMANDE SET NOM=:NOM,PRENOM=:PRENOM,DATEDENAISSANCE=:DATEDENAISSANCE,NUMEROTEL=:NUMEROTEL,ADRESSE=:ADRESSE,EMAIL=:EMAIL WHERE IDEMP=:IDEMP");
   query.bindValue(":IDEMP", idemp_string);
   query.bindValue(":NOM",nom);
   query.bindValue(":PRENOM",prenom);
   query.bindValue(":DATEDENAISSANCE",date_date);
   query.bindValue(":NUMEROTEL",numtel_string);
   query.bindValue(":ADRESSE",adr);
   query.bindValue(":EMAIL",mail);
   return query.exec();

}

QSqlQueryModel* employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM EMPLOYE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEMP"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE NAISSANCE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));

    return model;


}
bool employe::supprimer(int idemp)
{           QSqlQuery query;
            query.prepare(" Delete from COMMANDE where IDEMP=:IDEMP");
            query.bindValue(0,idemp);
           return query.exec();


}


/*QSqlQueryModel* Commande::chercher(int index,QString text)
{
QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(index==0)
   { query.prepare("SELECT * FROM COMMANDE where MODEDEPAIMENT like '"+text+"'");
     query.exec();
     model->setQuery(query);
     }
   if(index==1)
      {
       query.prepare("SELECT * FROM COMMANDE where REF_CLIENT like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==2)
      {
       query.prepare("SELECT * FROM COMMANDE where Adresse like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==3)
      {
       query.prepare("SELECT * FROM COMMANDE where NUMERO like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }

    return model;

}*/

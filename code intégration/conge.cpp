#include "conge.h"
#include "conge.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDate>
#include <QObject>
#include <QMessageBox>
#include <QVBoxLayout>

Conge::Conge()
{
    idemp=0;
    idc=0;
    nom="";
    prenom="";
    datedeb="";
    datefin="";
    duree=0;
    etat="";
}
Conge::Conge(int idc,QString nom,QString prenom,QString datedeb,QString datefin,int duree,QString etat,int idemp)
{
    this->idc=idc;
    this->idemp=idemp;
    this->nom=nom;
    this->prenom=prenom;
    this->datedeb=datedeb;
    this->datefin=datefin;
    this->duree=duree;
    this->etat=etat;
}
int Conge::getidc()
{
    return idc;
}

int Conge::getidemp()
{
    return idemp;
}

QString Conge::getnom()
{
    return nom;
}

QString Conge::getprenom()
{
    return prenom;
}

QString Conge::getdatedeb()
{
    return datedeb;
}

QString Conge::getdatefin()
{
    return datefin;
}

int Conge::getduree()
{
    return duree;
}

QString Conge::getetat()
{
    return etat;
}

void Conge ::setnom(QString n)
{
    nom=n;
}
void Conge ::setprenom(QString p)
{
    prenom=p;
}
void Conge::setdatedeb(QString deb)
{
    datedeb=deb;

}
void Conge ::setdatefin(QString fin)
{
    datefin=fin;
}
void Conge :: setduree(int d)
{
    duree=d;
}
void Conge :: setetat(QString et)
{
    etat=et;
}
void Conge::setidc(int ic)
{
    idc=ic;
}
void Conge::setidemp(int ie)
{
    idemp=ie;
}

bool Conge :: ajouterc()
{
    QSqlQuery query;
    QString idc_string=QString::number(idc);
    QString idemp_string=QString::number(idemp);
    QString duree_string=QString::number(duree);
    QDate deb_date =QDate::fromString(datedeb,"dd/MM/yy");
    QDate fin_date =QDate::fromString(datefin,"dd/MM/yy");
          query.prepare("INSERT INTO CONGE (IDC,NOM,PRENOM,DEB,FIN,DUREE,ETAT,IDEMP) "
                        "VALUES (:IDC,:NOM,:PRENOM,:DEB,:FIN,:DUREE,:ETAT,:IDEMP)");
          query.bindValue(":IDC", idc_string);
          query.bindValue(":NOM",nom);
          query.bindValue(":PRENOM",prenom);
          query.bindValue(":DEB",deb_date);
          query.bindValue(":FIN",fin_date);
          query.bindValue(":DUREE",duree_string);
          query.bindValue(":ETAT",etat);
          query.bindValue(":IDEMP", idemp_string);

          return query.exec();

}

bool Conge ::modifierc()
{
    QSqlQuery query;
    QString idc_string=QString::number(idc);
    QString idemp_string=QString::number(idemp);
    QString duree_string=QString::number(duree);
    QDate datedeb_date =QDate::fromString(datedeb,"dd/MM/yy");
    QDate datefin_date =QDate::fromString(datefin,"dd/MM/yy");
   query.prepare(" UPDATE CONGE SET IDEMP=:IDEMP,NOM=:NOM,PRENOM=:PRENOM,DEB=:DEB,FIN=:FIN,DUREE=:DUREE,ETAT=:ETAT WHERE IDC=:IDC");
   query.bindValue(":IDC",idc_string);
   query.bindValue(":NOM",nom);
   query.bindValue(":PRENOM",prenom);
   query.bindValue(":DEB",datedeb_date);
   query.bindValue(":FIN",datefin_date);
   query.bindValue(":DUREE",duree_string);
   query.bindValue(":ETAT",etat);
   query.bindValue(":IDEMP",idemp_string);
   return query.exec();

}

QSqlQueryModel* Conge::afficherc()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM CONGE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDC"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DEB"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("FIN"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("DUREE"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("IDEMP"));
    return model;


}

QSqlQueryModel *Conge::afficherE()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT IDEMP FROM EMPLOYE");

    return model;
}
bool Conge::supprimerc(int idc)
{           QSqlQuery query;
            query.prepare(" Delete from CONGE where IDC=:IDC");
            query.bindValue(0,idc);
           return query.exec();

}


QSqlQueryModel* Conge::chercherc(int index,QString text)
{
QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(index==0)
   { query.prepare("SELECT * FROM CONGE where IDC like '"+text+"'");
     query.exec();
     model->setQuery(query);
    }

   if(index==1)
      {
       query.prepare("SELECT * FROM CONGE where NOM like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==2)
      {
       query.prepare("SELECT * FROM CONGE where DUREE like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }

    return model;

}




QSqlQueryModel* Conge::trierc(int index)
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(index==0)
       { query.prepare("SELECT * FROM CONGE ORDER BY IDC DESC");
         query.exec();
         model->setQuery(query);
        }

       if(index==1)
          {
           query.prepare("SELECT * FROM CONGE ORDER BY NOM DESC");
               query.exec();
               model->setQuery(query);
       }
       if(index==2)
          {
           query.prepare("SELECT * FROM CONGE ORDER BY DUREE DESC");
               query.exec();
               model->setQuery(query);
       }

        return model;

    }




Conge* Conge::readconge (QString val)
{
 QSqlQuery query;
    query.prepare("Select * FROM CONGE where IDC='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {  qDebug()<<"test"<<val;

              setidc(query.value(0).toInt());
              setnom(query.value(1).toString());
             setprenom(query.value(2).toString());
             setdatedeb(query.value(3).toString());
             setdatefin(query.value(4).toString());
             setduree(query.value(5).toInt());
             setetat(query.value(6).toString());
             setidemp(query.value(7).toInt());

            }
        }
     return this;
}

int Conge::verifid(int id)
{
    bool test=false;
          QSqlQuery  query;
          QString num_string=QString::number(id);
                 query.prepare("SELECT * FROM conge where IDC=:idemp");
                  query.bindValue(":idemp",num_string);
             if(query.exec()&&query.next())
             {     test=true;
                  return test;
             }
             return test;



}

#include "vehicule.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
Vehicule::Vehicule()
{
  matricule=numdechassis=marque=typecarburant=typev=typecarburant=datecirculation="";
  idemp=0;
}

Vehicule::Vehicule(QString matricule,QString numdechassis,QString typec,QString typev,QString datecirculation,QString marque,int idemp)
{

this->matricule=matricule;
this->numdechassis=numdechassis;
typecarburant=typec;
this->typev=typev;
this->datecirculation=datecirculation;
this->idemp=idemp;
this->marque=marque;

}
QString Vehicule ::  getmatricule()
{
    return matricule;

}
QString Vehicule ::getnumdechassis()
{
    return numdechassis;


}
QString Vehicule :: getmarque()
{
    return marque;

}
QString Vehicule ::gettypev()
{

  return typev;
}
QString Vehicule ::gettypecarburant()
{

   return typecarburant;
}
QString Vehicule ::getdatecirculation()
{
    return datecirculation;
}
int Vehicule:: getidemp()
{
    return idemp;
}
void Vehicule:: setmatricule(QString m)
{
    matricule=m;
}
void Vehicule:: setnumdechassis(QString num)
{
    numdechassis=num;
}
void Vehicule:: setmarque(QString m)
{
    marque=m;
}
void Vehicule::settypecarburant(QString typec)
{
    typecarburant=typec;
}
void Vehicule::setdatecirculation(QString d)
{
    datecirculation=d;
}
bool Vehicule:: ajouter()
{
    QSqlQuery query;
    QString Idemp_string=QString::number(idemp);
    QDate detecirculation_d =QDate::fromString(datecirculation,"dd/MM/yy");
          query.prepare("INSERT INTO vehicule(matricule,numdechassis,marque,typev,typecarburant,datecirculation,idemp) "
                        "VALUES (:matricule,:numdechassis,:marque,:typev,:typecarburant,:datecirculation,:idemp)");
          query.bindValue(":matricule",matricule);
          query.bindValue(":numdechassis",numdechassis);
          query.bindValue(":marque",marque);
             query.bindValue(":typev",typev);
          query.bindValue(":typecarburant",typecarburant);
          query.bindValue(":idemp",Idemp_string);
          query.bindValue(":datecirculation",detecirculation_d);
          return query.exec();

}
bool Vehicule ::modifier()
{
    QSqlQuery query;
    QString Idemp_string=QString::number(idemp);
    QDate detecirculation_d =QDate::fromString(datecirculation,"dd/MM/yy");
 query.prepare("UPDATE vehicule SET numdechassis=:numdechassis,marque=:marque,typev=:typev,typecarburant=:typecarburant,datecirculation=:datecirculation,idemp=:idemp WHERE matricule=:matricule");
 query.bindValue(":matricule",matricule);
 query.bindValue(":numdechassis",numdechassis);
 query.bindValue(":marque",marque);
 query.bindValue(":typev",typev);
 query.bindValue(":typecarburant",typecarburant);
 query.bindValue(":idemp",Idemp_string);
 query.bindValue(":datecirculation",detecirculation_d);
   return query.exec();
}

QSqlQueryModel* Vehicule ::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM vehicule");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("numdechassis"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("type vehicule"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("typecarburant"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("id employee"));

    return model;

}
bool Vehicule :: supprimer(QString matricule)
{
              QSqlQuery query;
               query.prepare("Delete from vehicule where matricule=:matricule");
               query.bindValue(0,matricule);
              return query.exec();
}

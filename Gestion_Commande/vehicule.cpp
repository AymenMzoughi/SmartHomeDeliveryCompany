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
void Vehicule ::settypev(QString tv)
{

   typev=tv;
}
void Vehicule::setdatecirculation(QString d)
{
    datecirculation=d;
}
void Vehicule::setidemp(int emp)
{
    idemp=emp;
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

QSqlQueryModel* Vehicule::chercher(int index , QString text)
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(index==0)
       { query.prepare("SELECT * FROM VEHICULE where matricule like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(index==1)
          {
           query.prepare("SELECT * FROM VEHICULE where marque like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(index==2)
          {
           query.prepare("SELECT * FROM VEHICULE where typev like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(index==3)
          {
           query.prepare("SELECT * FROM VEHICULE where typecarburant like '"+text+"'");
               query.exec();
            model->setQuery(query);
       }

        return model;


}
int Vehicule::statistique1()
{ QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from Vehicule where typev like 'camion' ") ;
        while(requete.next())
        {
                count++ ;
        }

    return count ;

}
int Vehicule::statistique2()
{ QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from Vehicule where typev like 'moto' ") ;
        while(requete.next())
        {
                count++ ;
        }

    return count ;

}
int Vehicule::statistique3()
{
        int count=0 ;
        QSqlQuery requete("select * from Vehicule where typev like 'tricycle' ") ;
        while(requete.next())
        {
                count++ ;
        }

    return count ;

}
bool Vehicule ::verifvide(QString S)
  {      bool test=true;
        if(S.length()==0)
         {  test=false;
            return test;}
        return test;
}
 QSqlQueryModel* Vehicule:: affiche_employer()
 {

     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_EMP from employe");
     return model ;
 }
 bool Vehicule::verifierMatricule(QString Matricule)
 {QSqlQuery  query;
 bool test=false;
     query.prepare("Select * FROM vehicule where matricule=:matricule");
      query.bindValue(":matricule",Matricule);
 if(query.exec()&&query.next())
 {     test=true;
      return test;
 }
 return test;
 }
 bool Vehicule ::verifint(QString S)
 {bool test=false;
     char *suiteChaine;

         char *myChar = S.toLatin1().data();
         suiteChaine =strstr(myChar,"Tunis");
         if (suiteChaine != NULL)
         {  test=true;
             return test;
         }

return test;
 }
Vehicule* Vehicule:: readvehicule(QString val)
{
    QSqlQuery query;
       query.prepare("Select * FROM vehicule where matricule='"+val+"'");
           if(query.exec())
           {     while(query.next())
               {  qDebug()<<"test"<<val;
                  setmatricule(query.value(0).toString());
                 setnumdechassis(query.value(1).toString());
                setmarque(query.value(2).toString());
               settypev(query.value(3).toString());
                settypecarburant(query.value(4).toString());
                setdatecirculation(query.value(5).toString());
                setidemp(query.value(6).toInt());

               }
           }
        return this;

}

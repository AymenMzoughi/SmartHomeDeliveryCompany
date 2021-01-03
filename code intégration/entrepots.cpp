#include "entrepots.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
Entrepots::Entrepots()
{
  ref=0;
  region="";
  adresse="";
  nsalles=0;
  nvehicules=0;
}

Entrepots::Entrepots(int r,QString rg,QString a,int ns,int nv)
{
 this->ref=r;
 this->region=rg;
 this->adresse=a;
 this->nsalles=ns;
 this->nvehicules=nv;

}
int Entrepots::getref()
{
    return ref;
}

QString Entrepots::getregion()
{
    return region;
}

QString Entrepots::getadresse()
{
    return adresse;
}
int Entrepots::getnsalles()
{
    return nsalles;
}
int Entrepots::getnvehicules()
{
    return nvehicules;
}

void Entrepots::setref(int ref)
{
    this->ref=ref;
}
void Entrepots::setregion(QString region)
{
    this->region=region;
}
void Entrepots::setadresse(QString adresse)
{
    this->adresse=adresse;
}
void Entrepots::setnsalles(int nsalles)
{
    this->nsalles=nsalles;
}
void Entrepots::setnvehicules(int nvehicules)
{
    this->nvehicules=nvehicules;
}

bool Entrepots:: ajouter()
{    QSqlQuery query;
     QString ref_string=QString::number(ref);//à revenir
     QString nb_v=QString::number(nvehicules);
      QString nb_s=QString::number(nsalles);
          query.prepare("INSERT INTO Entrepots(ref,adresse,region,nsalles,nvehicules) "
                        "VALUES (:ref,:adresse,:region,:nsalles,:nvehicules)");
          query.bindValue(":ref",ref_string);
          query.bindValue(":adresse",adresse);
          query.bindValue(":region",region);
          query.bindValue(":nsalles",nb_s);
          query.bindValue(":nvehicules",nb_v);

          return query.exec();

}
bool Entrepots ::modifier()
{
    QSqlQuery query;
    QString ref_string=QString::number(ref);//à revenir
    QString nb_v=QString::number(nvehicules);
     QString nb_s=QString::number(nsalles);
 query.prepare("UPDATE Entrepots SET ref=:ref,adresse=:adresse,region=:region,nsalles=:nsalles,nvehicules=:nvehicules WHERE ref=:ref");
 query.bindValue(":ref",ref_string);
 query.bindValue(":adresse",adresse);
 query.bindValue(":region",region);
 query.bindValue(":nsalles",nb_s);
 query.bindValue(":nvehicules",nb_v);

   return query.exec();
}

QSqlQueryModel* Entrepots ::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Entrepots");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("region"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("nsalles"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("nvehicules"));


    return model;

}
bool Entrepots :: supprimer(int ref)
{
              QSqlQuery query;
              QString ref_string=QString::number(ref);//à revenir
               query.prepare("Delete from Entrepots where ref=:ref");
                 query.bindValue(":ref",ref_string);
              return query.exec();
}

QSqlQueryModel* Entrepots::chercher(int index , QString text)//à revenir
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(index==0)
       { query.prepare("SELECT * FROM Entrepots where ref like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(index==1)
          {
           query.prepare("SELECT * FROM Entrepots where adresse like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(index==2)
          {
           query.prepare("SELECT * FROM Entrepots where region like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(index==3)
          {
           query.prepare("SELECT * FROM Entrepots where nsalles like '"+text+"'");
               query.exec();
            model->setQuery(query);
       }

        return model;


}


bool Entrepots ::verifvide(QString S)
  {      bool test=true;
        if(S.length()==0)
         {  test=false;
            return test;}
        return test;
}
 QSqlQueryModel* Entrepots:: affiche_entrepots()
 {

     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_EMP from entrepots");
     return model ;
 }
 bool Entrepots::verifierref(int ref)
 {QSqlQuery  query;
 bool test=false;
     query.prepare("Select * FROM Entrepots where ref=:ref");
      query.bindValue(":ref",ref);
 if(query.exec()&&query.next())
 {     test=true;
      return test;
 }
 return test;
 }
 bool Entrepots::verifiregion(QString S) // à revenir
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
Entrepots* Entrepots:: readEntrepots(QString val)
{
    QSqlQuery query;
       query.prepare("Select * FROM Entrepots where ref='"+val+"'");
           if(query.exec())
           {     while(query.next())
               {  qDebug()<<"test"<<val;
                  setref(query.value(0).toInt());
                 setadresse(query.value(1).toString());
                setregion(query.value(2).toString());
               setnsalles(query.value(3).toInt());
                setnvehicules(query.value(6).toInt());

               }
           }
        return this;

}

QSqlQueryModel *Entrepots::trierc(int index)
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(index==0)
       { query.prepare("SELECT * FROM Entrepots  ORDER BY ref DESC");
         query.exec();
         model->setQuery(query);
        }

       if(index==1)
          {
           query.prepare("SELECT * FROM Entrepots  ORDER BY adresse DESC");
               query.exec();
               model->setQuery(query);
       }
       if(index==2)
          {
           query.prepare("SELECT * FROM Entrepots ORDER BY nsalles DESC");
               query.exec();
               model->setQuery(query);
       }

        return model;
}

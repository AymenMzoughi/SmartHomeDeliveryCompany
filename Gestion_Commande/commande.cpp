#include "commande.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
Commande::Commande()
{
    num=0;
    montant=0;
    description="";
    datedecommande="";
    adresse="";
    modepaiment="";
    idclient=0;
}
Commande::Commande(int num,QString description ,QString datedecommande,QString adresse,QString modepaiment,float montant,int idclient)
{
this->num=num;
this->description=description;
this->datedecommande=datedecommande;
this->adresse=adresse;
 this->modepaiment=modepaiment;
this->montant=montant;
this->idclient=idclient;


}
int Commande::getidclient()
{
    return idclient;
}
int Commande:: getnum()
{
    return num;
}
QString Commande ::getdescription()
{
    return description;
}
QString Commande:: getadresse()
{
    return adresse;
}
QString Commande:: getdatecommande()
{
    return datedecommande;
}
QString Commande:: getmodepaiment()
{
    return modepaiment;
}
float Commande ::getmontant()
{
    return montant;
}
void Commande:: setdescription(QString d)
{
    description=d;
}
void Commande ::setadresse(QString a)
{
    adresse=a;
}
void Commande::setdatecommande(QString datec)
{
    datedecommande=datec;

}
void Commande ::setmodepaiment(QString mp)
{
    modepaiment=mp;
}
void Commande :: setmontant(float m)
{
    montant=m;
}
void Commande :: setnum(int n)
{
    num=n;
}
void Commande ::setidclient(int id)
{
    idclient=id;
}
bool Commande :: ajouter()
{
    QSqlQuery query;
    QString num_string=QString::number(num);
    QString id_string=QString::number(idclient);
    QString montant_string=QString::number(montant, 'g', 4);
    QDate datedecommannde_date =QDate::fromString(datedecommande,"dd/MM/yy");
          query.prepare("INSERT INTO COMMANDE (NUMERO,DESCRIPTION,ADRESSE,DATEDECOMMANDE,MODEDEPAIMENT,MONTANT,REF_CLIENT) "
                        "VALUES (:NUMERO,:DESCRIPTION,:ADRESSE,:DATEDECOMMANDE,:MODEDEPAIMENT,:MONTANT,:REF_CLIENT)");
          query.bindValue(":NUMERO", num_string);
          query.bindValue(":DATEDECOMMANDE",datedecommannde_date);
          query.bindValue(":ADRESSE",adresse);
             query.bindValue(":DESCRIPTION",description);
          query.bindValue(":MODEDEPAIMENT",modepaiment);
          query.bindValue(":MONTANT",montant_string);
          query.bindValue(":REF_CLIENT",id_string);
          return query.exec();

}
bool Commande ::modifier()
{
    QSqlQuery query;
    QString num_string=QString::number(num);
    QString id_string=QString::number(idclient);
    QString montant_string=QString::number(montant, 'g', 4);
    QDate datedecommannde_date =QDate::fromString(datedecommande,"dd/MM/yy");
   query.prepare(" UPDATE COMMANDE SET DESCRIPTION=:DESCRIPTION,ADRESSE=:ADRESSE,DATEDECOMMANDE=:DATEDECOMMANDE,MODEDEPAIMENT=:MODEDEPAIMENT,MONTANT=:MONTANT,REF_CLIENT=:REF_CLIENT WHERE NUMERO=:NUMERO");
          query.bindValue(":NUMERO", num_string);
          query.bindValue(":DATEDECOMMANDE",datedecommannde_date);
          query.bindValue(":ADRESSE",adresse);
             query.bindValue(":DESCRIPTION",description);
          query.bindValue(":MODEDEPAIMENT",modepaiment);
          query.bindValue(":MONTANT",montant_string);
          query.bindValue("REF_CLIENT",id_string);
          return query.exec();

}
QSqlQueryModel* Commande::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM COMMANDE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE COMMANDE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("MODEDEPAIMENT"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("MONTANT"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("REF_CLIENT"));

    return model;


}
bool Commande::supprimer(int num)
{           QSqlQuery query;
            query.prepare(" Delete from COMMANDE where NUMERO=:NUMERO");
            query.bindValue(0,num);
           return query.exec();



}


QSqlQueryModel* Commande::chercher(int index,QString text)
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

}

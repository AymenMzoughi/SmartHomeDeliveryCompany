#include "commande.h"
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
    modepaiment="";
    idclient=0;
    idemp="";
}
Commande::Commande(int num,QString description ,QString datedecommande,QString modepaiment,float montant,int idclient,QString idemp)
{
this->num=num;
this->description=description;
this->datedecommande=datedecommande;
 this->modepaiment=modepaiment;
this->montant=montant;
this->idclient=idclient;
this->idemp=idemp;


}
int Commande::getidclient()
{
    return idclient;
}
QString Commande::getidemp()
{
    return idemp;
}
int Commande:: getnum()
{
    return num;
}
QString Commande ::getdescription()
{
    return description;
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
void Commande::setdatecommande(QString datec)
{
    datedecommande=datec;

}
void Commande::setidemp(QString id)
{
    idemp=id;

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
bool Commande ::verifint(int S)
{
    bool test=true;
        if(S==0)
         {  test=false;
            return test;}
        return test;

}
bool Commande::veriffloat(float F)
{
    bool test=true;
        if(F==0)
         {  test=false;
            return test;}
        return test;
}
bool Commande :: ajouter()
{
    QSqlQuery query;
    QString num_string=QString::number(num);
    QString id_string=QString::number(idclient);
    QString montant_string=QString::number(montant, 'f', 4);
    QDate datedecommannde_date =QDate::fromString(datedecommande,"dd/MM/yy");
    query.prepare("INSERT INTO COMMANDE (NUMERO,DESCRIPTION,DATEDECOMMANDE,MODEDEPAIMENT,MONTANT,ID_EMP,REF_CLIENT) "
                           "VALUES (:NUMERO,:DESCRIPTION,:DATEDECOMMANDE,:MODEDEPAIMENT,:MONTANT,:ID_EMP,:REF_CLIENT)");
          query.bindValue(":NUMERO", num_string);
          query.bindValue(":DATEDECOMMANDE",datedecommannde_date);
             query.bindValue(":DESCRIPTION",description);
          query.bindValue(":MODEDEPAIMENT",modepaiment);
          query.bindValue(":MONTANT",montant_string);
          query.bindValue(":REF_CLIENT",id_string);
          query.bindValue(":ID_EMP",idemp);
          return query.exec();

}
bool Commande ::modifier()
{
    QSqlQuery query;
    QString num_string=QString::number(num);
    QString montant_string=QString::number(montant,'f',4);
    QString client_string=QString::number(idclient);
    QDate datedecommannde_date =QDate::fromString(datedecommande,"dd/MM/yy");
   query.prepare("UPDATE COMMANDE SET DESCRIPTION=:DESCRIPTION,DATEDECOMMANDE=:DATEDECOMMANDE,MODEDEPAIMENT=:MODEDEPAIMENT,MONTANT=:MONTANT,REF_CLIENT=:REF_CLIENT,ID_EMP=:ID_EMP WHERE NUMERO=:NUMERO");
          query.bindValue(":NUMERO",num_string);
          query.bindValue(":DESCRIPTION",description);
          query.bindValue(":DATEDECOMMANDE",datedecommannde_date);
          query.bindValue(":MODEDEPAIMENT",modepaiment);
          query.bindValue(":MONTANT",montant_string);
          query.bindValue(":REF_CLIENT",client_string);
            query.bindValue(":ID_EMP",idemp);
          return query.exec();

}
QSqlQueryModel* Commande::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM COMMANDE");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE DE COMMANDE"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODEDEPAIMENT"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("REF_CLIENT"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_EMP"));
    return model;


}
bool Commande::supprimer(int num)
{           QSqlQuery query;
             QString num_string=QString::number(num);
            query.prepare("Delete from COMMANDE where NUMERO=:NUMERO");
            query.bindValue(":NUMERO",num_string);
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
       query.prepare("SELECT * FROM COMMANDE where NUMERO like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }

    return model;

}
bool Commande::verifvidestring(QString S)
{
    bool test=true;
        if(S.length()==0)
         {  test=false;
            return test;}
        return test;
}
bool Commande::verifierid(int numero)
{  QSqlQuery  query;
    bool test=false;
      QString num_string=QString::number(numero);
        query.prepare("Select * FROM COMMANDE where NUMERO=:NUMERO");
         query.bindValue(":NUMERO",num_string);
    if(query.exec()&&query.next())
    {     test=true;
         return test;
    }
    return test;
}
QSqlQueryModel * Commande::afficher_idclient()
{
    QSqlQueryModel * model =new QSqlQueryModel();
       model->setQuery("select Ref_c from  clients");
       return model ;

}
QSqlQueryModel * Commande::afficher_idemp()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select IDEMP from  EMPLOYE");
     return model ;

}
Commande* Commande::readcommande( QString val)
{
 QSqlQuery query;
    query.prepare("Select * FROM COMMANDE where NUMERO='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {  qDebug()<<"test"<<val;
               setnum(query.value(0).toInt());
              setdescription(query.value(1).toString());
             setdatecommande(query.value(2).toString());
             setmodepaiment(query.value(3).toString());
              setmontant(query.value(4).toFloat());
             setidclient(query.value(5).toInt());
             setidemp(query.value(6).toString());

            }
        }
     return this;
}


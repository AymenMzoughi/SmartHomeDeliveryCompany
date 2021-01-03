#include "colis.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
colis::colis()
{
    code_barre=0;
    poids=longeur=largeur=hauteur=0;

}
colis::colis(int code_barre,float poids,float longeur,float largeur,float hauteur)
{
this->code_barre=code_barre;
this->poids=poids;
this->longeur=longeur;
this->largeur=largeur;
this->hauteur=hauteur;
}
int colis::getcode_barre()
{
    return code_barre;
}
float colis::getpoids()
{
    return poids;
}
float colis:: getlongeur()
{
    return longeur;
}
float colis ::getlargeur()
{
    return largeur;
}
float colis:: gethauteur()
{
    return hauteur;
}

void colis:: setcode_barre(int val)
{
    code_barre=val;
}
void colis::setpoids(float p)
{
    poids=p;

}
void colis::setlongeur(float lo)
{
    longeur=lo;

}
void colis ::setlargeur(float la)
{
   largeur=la ;
}
void colis :: sethauteur(float h)
{
    hauteur=h;
}

bool colis ::verifint(int S)// à revenir
{
    bool test=true;
        if(S==0)
         {  test=false;
            return test;}
        return test;

}
bool colis::veriffloat(float F)// à revenir
{
    bool test=true;
        if(F==0)
         {  test=false;
            return test;}
        return test;
}
bool colis :: ajouter()
{
    QSqlQuery query;
    QString code_bare_s=QString::number(code_barre);//à revenir
    QString poids_s=QString::number(poids, 'f', 4);
     QString longeur_s=QString::number(longeur, 'f', 4);
      QString largeur_s=QString::number(largeur, 'f', 4);
       QString hauteur_s=QString::number(hauteur, 'f', 4);
          query.prepare("INSERT INTO Colis (CODE_BARE,POIDS,LONGEUR,LARGEUR,HAUTEUR) "
                        "VALUES (:CODE_BARRE,:POIDS,:LONGEUR,:LARGEUR,:HAUTEUR)");
          query.bindValue(":CODE_BARRE", code_bare_s);
          query.bindValue(":POIDS",poids_s);
             query.bindValue(":LONGEUR",longeur_s);
          query.bindValue(":LARGEUR",largeur_s);
          query.bindValue(":HAUTEUR",hauteur_s);

          return query.exec();

}
bool colis ::modifier()
{
    QSqlQuery query;
    QString code_bare_s=QString::number(code_barre);//à revenir
    QString poids_s=QString::number(poids, 'f', 4);
     QString longeur_s=QString::number(longeur, 'f', 4);
      QString largeur_s=QString::number(largeur, 'f', 4);
       QString hauteur_s=QString::number(hauteur, 'f', 4);
   query.prepare("UPDATE colis SET POIDS=:POIDS,LONGEUR=:LONGEUR,LARGEUR=:LARGEUR,HAUTEUR=:HAUTEUR WHERE code_bare=:CODE_BARRE");// à revenir
   query.bindValue(":CODE_BARRE", code_bare_s);
   query.bindValue(":POIDS",poids_s);
      query.bindValue(":LONGEUR",longeur_s);
   query.bindValue(":LARGEUR",largeur_s);
   query.bindValue(":HAUTEUR",hauteur_s);
          return query.exec();

}
QSqlQueryModel*colis::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Colis");
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("CODE_BARRE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("POIDS"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LONGEUR"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("LARGEUR"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("HAUTEUR"));

    return model;


}
bool colis::supprimer(int code)
{           QSqlQuery query;
             QString code_bare_s=QString::number(code);
            query.prepare("Delete from Colis where CODE_BARE=:CODE_BARRE");
           query.bindValue(":CODE_BARRE", code_bare_s);
            return query.exec();



}


QSqlQueryModel* colis::chercher(int index,QString text)//à revenir noms variables
{
   QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(index==0)
   { query.prepare("SELECT * FROM colis where Longeur like '"+text+"'");
        // à revenir mode de paimenet
     query.exec();
     model->setQuery(query);
     }
   if(index==1)
      {
       query.prepare("SELECT * FROM colis where poids like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==2)
      {qDebug()<<index;
       qDebug()<<text;
      query.prepare("SELECT * FROM colis where code_bare like ' "+text+" '");

           bool test=query.exec();
           qDebug()<<test;
           model->setQuery(query);
   }

    return model;

}
bool colis::verifvidestring(QString S)// à revenir
{
    bool test=true;
        if(S.length()==0)
         {  test=false;
            return test;}
        return test;
}
bool colis::verifierid(int numero)// à revenir
{  QSqlQuery  query;
    bool test=false;
      QString num_string=QString::number(numero);// à reveniir
        query.prepare("Select * FROM Colis where CODE_BARE=:CODE_BARRE");
         query.bindValue(":CODE_BARRE",num_string);
    if(query.exec()&&query.next())
    {     test=true;
         return test;
    }
    return test;
}
QSqlQueryModel * colis::afficher_idclient() // à revenir
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select REFCLIENT from  client");
     return model ;

}
QSqlQueryModel * colis::afficher_idemp() // à revenir
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_EMP from  EMPLOYE");
     return model ;

}
colis* colis::readColis( QString val)
{
 QSqlQuery query;
    query.prepare("Select * FROM Colis where CODE_BARE='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {  qDebug()<<"test"<<val;
               sethauteur(query.value(0).toFloat());
              setlargeur(query.value(1).toFloat());
            setlongeur(query.value(2).toFloat());
            setcode_barre(query.value(3).toFloat());
            setpoids(query.value(4).toFloat());


            }
        }
        return this;
}

QSqlQueryModel *colis::trierc(int index)
{
    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(index==0)
       { query.prepare("SELECT * FROM colis ORDER BY code_bare DESC");
         query.exec();
         model->setQuery(query);
        }

       if(index==1)
          {
           query.prepare("SELECT * FROM colis ORDER BY poids DESC");
               query.exec();
               model->setQuery(query);
       }
       if(index==2)
          {
           query.prepare("SELECT * FROM colis ORDER BY largeur DESC");
               query.exec();
               model->setQuery(query);
       }

        return model;



}

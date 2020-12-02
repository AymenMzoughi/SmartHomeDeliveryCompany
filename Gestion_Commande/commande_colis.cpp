#include "commande_colis.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
Commande_colis::Commande_colis()
{

}
Commande_colis::Commande_colis(int commande,int colis,QString etat)
{

    numeroc=commande;
    id_colis=colis;
    this->etat=etat;


}
QSqlQueryModel * Commande_colis::afficher_idcommande()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select NUMERO from commande ");
     return model ;

}
QSqlQueryModel * Commande_colis::afficher_idcolis()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select code_bare from  colis");
     return model ;

}
  bool Commande_colis::affecteruncolis()
  {
      QSqlQuery query;
      QString numeroc_string=QString::number(numeroc);
      QString codecolis_string=QString::number(id_colis);
            query.prepare("INSERT INTO COMMANDE_COLIS (NUMERO_C,ETAT,CODE_COLIS) "
                          "VALUES (:NUMERO_C,:ETAT,:CODE_COLIS)");
            query.bindValue(":NUMERO_C", numeroc_string);
            query.bindValue(":ETAT",etat);
            query.bindValue(":CODE_COLIS",codecolis_string);
            return query.exec();

  }
  bool Commande_colis::verifvidestring(QString S)
  {
      bool test=true;
          if(S.length()==0)
           {  test=false;
              return test;}
          return test;
  }
  bool Commande_colis::updateetat(int num)
  {
      QSqlQuery query;
        QString numeroc_string=QString::number(num);
      query.prepare(" UPDATE  COMMANDE_COLIS SET etat='annulee' where NUMERO_C=:NUMERO_C");
      query.bindValue(":NUMERO_C", numeroc_string);
      return query.exec();

  }
bool Commande_colis::verifiercommandeaff(int num)
{QSqlQuery  query;
        bool test=false;
          QString num_string=QString::number(num);
            query.prepare("Select * FROM COMMANDE_COLIS where NUMERO_C=:NUMERO_C");
             query.bindValue(":NUMERO_C",num_string);
        if(query.exec()&&query.next())
        {     test=true;
             return test;
        }
        return test;

}
int Commande_colis::verifcommandeidclient(int num)
{QSqlQuery  query;
   int idclient=0;
      QString num_string=QString::number(num);
        query.prepare("Select REF_CLIENT FROM COMMANDE where NUMERO=:NUMERO ");
        query.bindValue(":NUMERO",num_string);
        query.exec();

    while (query.next()) {
         idclient = query.value(0).toInt();
           qDebug()<<"  id client dans commande"<<idclient ;
       }
   return idclient;
}
int Commande_colis::verifiercolis(int colis)
{QSqlQuery  query;
      int rcolis=0;
          QString num_string=QString::number(colis);
            query.prepare("Select numero_c FROM COMMANDE_Colis where code_colis=:code_colis ");
            query.bindValue(":code_colis",num_string);
            query.exec();
        while (query.next()) {
           rcolis = query.value(0).toInt();
               qDebug()<<" code colis de commande from commande_colis "<< rcolis ;
           }

       return rcolis;

}

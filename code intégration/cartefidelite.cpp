#include "cartefidelite.h"

CarteFidelite::CarteFidelite()
{
    numero=points=cheque=0;
}

CarteFidelite::CarteFidelite(int numero,int points,int cheque,QDate date_em,QDate date_ex,int refer_clients)
{
    this->numero=numero;
    this->points=points;
    this->cheque=cheque;
    this->date_em=date_em;
    this->date_ex=date_ex;
    this->refer_clients=refer_clients;

}
int CarteFidelite:: getNum(){return numero;}
int CarteFidelite::getPoints(){return points;}
int CarteFidelite:: getCheque(){return cheque;}
QDate CarteFidelite:: getDateEm(){return date_em;}
QDate CarteFidelite::getDateEx(){ return date_ex ;}
void CarteFidelite::setNum(int numero){this->numero=numero;}
void CarteFidelite::setPoints(int points){this->points=points;}
void CarteFidelite::setCheque(int cheque){this->cheque=cheque;}
void CarteFidelite::setDateEm(QDate date_em){this->date_em=date_em;}
void CarteFidelite::setDateEx(QDate date_ex){this->date_ex=date_ex;}
bool CarteFidelite::ajouter()
{

    QSqlQuery query;

    QString numero_string= QString::number(numero);
    QString points_string= QString::number(points);
    QString cheque_string= QString::number(cheque);
    QString ref_str= QString::number(refer_clients);
          query.prepare("INSERT INTO cartefidelite (numero, points, cheque, date_em, date_ex,refer_clients) "
                        "VALUES (:numero, :points, :cheque, :date_em, :date_ex, :refer_clients)  ");
          query.bindValue(":numero", numero_string);
          query.bindValue(":points", points_string);
          query.bindValue(":cheque", cheque_string);
           query.bindValue(":date_em", date_em);
            query.bindValue(":date_ex", date_ex);
             query.bindValue(":refer_clients", ref_str);



          return query.exec();
}
QSqlQueryModel* CarteFidelite::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM cartefidelite ");


    return model;

}
bool CarteFidelite:: supprimer(int numero)
{
    QSqlQuery query;

    QString numero_string= QString::number(numero);
    QString points_string= QString::number(points);
    QString cheque_string= QString::number(cheque);
          query.prepare("DELETE FROM cartefidelite where numero=:numero");
          query.bindValue(0, numero);

    return query.exec();

}
bool CarteFidelite::modifier()
{
    QSqlQuery query;

    QString numero_string= QString::number(numero);
    QString points_string= QString::number(points);
    QString cheque_string= QString::number(cheque);
    query.prepare("UPDATE cartefidelite set  points=:points ,cheque =:cheque,date_em=:date_em, date_ex=:date_ex  WHERE numero=:numero");
    query.bindValue(":numero", numero_string);
    query.bindValue(":points", points_string);
    query.bindValue(":cheque", cheque_string);
     query.bindValue(":date_em", date_em);
      query.bindValue(":date_ex", date_ex);

    return query.exec();
}

QSqlQueryModel * CarteFidelite:: afficher_choix(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

     if(choix=="numeros décroissants")
    {
        model->setQuery("SELECT * FROM cartefidelite  ORDER BY numero DESC ;");
    }
    else if(choix=="numeros croissants")
    {
        model->setQuery("SELECT * FROM cartefidelite  ORDER BY numero ASC;");
    }
     else if(choix=="date emission croissant")
     {
         model->setQuery("SELECT * FROM cartefidelite  ORDER BY date_em ASC;");
     }
     else if(choix=="date emission decroissant")
     {
         model->setQuery("SELECT * FROM cartefidelite  ORDER BY date_em DESC;");
     }
     else if(choix=="date expiration croissant")
     {
         model->setQuery("SELECT * FROM cartefidelite  ORDER BY date_ex ASC;");
     }
     else if(choix=="date expiration decroissant")
     {
         model->setQuery("SELECT * FROM cartefidelite  ORDER BY date_ex DESC;");
     }
    else if (choix=="choisir")
    {
        model->setQuery("SELECT * FROM cartefidelite ");
    }


    return model;

}

QSqlQueryModel * CarteFidelite::afficher_recherche2(QString b)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString numero_string= QString::number(numero);
    QString points_string= QString::number(points);
    QString cheque_string= QString::number(cheque);
    model->setQuery("SELECT * FROM cartefidelite where numero='"+b+"' ");

    return model ;

}
QSqlQueryModel * CarteFidelite:: afficher_recherche(QString b)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM cartefidelite where date_em='"+b+"' ");

    return model ;
}
QSqlQueryModel *CarteFidelite:: afficher_recherche3(QString b)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM cartefidelite where points='"+b+"' ");

    return model ;
}


QSqlQueryModel * CarteFidelite:: afficher_ref()
{
    QSqlQueryModel * model =new QSqlQueryModel();
          model->setQuery("select Ref_c from clients ");
          return model ;
}

QSqlQueryModel * CarteFidelite::afficher_numero()
{
    QSqlQueryModel * model =new QSqlQueryModel();
          model->setQuery("select numero from cartefidelite ");
          return model ;
}




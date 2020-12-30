#include "clients.h"

Clients::Clients()
{
    Ref_c=telephone=0;
    Email=nom_c=pays=adresse="";
}
Clients::Clients(int Ref_c,int telephone,QString Email,QString nom_c,QString pays,QString adresse)
{
    this->Ref_c=Ref_c;
    this->telephone=telephone;
    this->Email=Email;
    this->nom_c=nom_c;
    this->pays=pays;
    this->adresse=adresse;

}
int Clients::getRef(){return Ref_c;}
int Clients::getTel(){return telephone;}
QString Clients::getEmail(){return Email;}
QString Clients:: getnom(){return nom_c;}
QString Clients::getPays(){return pays;}
QString Clients::getadr(){return adresse;}
void Clients::setRef(int Ref_c){this->Ref_c=Ref_c;}
void Clients::setTel(int telephone){this->telephone=telephone;}
void Clients:: setEmail(QString Email){this->Email=Email;}
void Clients::setNom(QString nom_c){this->nom_c=nom_c;}
void Clients::setPays(QString pays){this->pays=pays;}
void Clients::setadr(QString adresse){this->adresse=adresse;}

bool Clients:: ajouter()
{

    QSqlQuery query;

    QString telephone_string= QString::number(telephone);
    QString ref_string= QString::number(Ref_c);

          query.prepare("INSERT INTO clients (Ref_c, telephone, Email, nom_c, pays, adresse) "
                        "VALUES (:ref, :tel, :email, :nom, :pays, :adr)");
          query.bindValue(":ref", ref_string);
          query.bindValue(":tel", telephone_string);
          query.bindValue(":email", Email);
           query.bindValue(":nom", nom_c);
            query.bindValue(":pays", pays);
             query.bindValue(":adr", adresse);


          return query.exec();
}

QSqlQueryModel* Clients::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM clients");

    return model;
}

bool Clients::supprimer(int Ref_c)
{
    QSqlQuery query;
    QString telephone_string= QString::number(telephone);
    QString ref_string= QString::number(Ref_c);
          query.prepare("DELETE FROM clients where Ref_c=:Ref_c ");
          query.bindValue(0, Ref_c);

    return query.exec();
}
bool Clients::modifier()
{
    QSqlQuery query;

    QString telephonee= QString::number(telephone);
    QString ref_string= QString::number(Ref_c);
    query.prepare("UPDATE clients set  telephone=:tel ,Email =:emaile,nom_c=:nom, pays=:payss, adresse=:adr WHERE Ref_c=:Ref_c");
    query.bindValue(":Ref_c", ref_string);
    query.bindValue(":tel", telephonee);
    query.bindValue(":emaile", Email);
     query.bindValue(":nom", nom_c);
      query.bindValue(":payss", pays);
       query.bindValue(":adr", adresse);
qDebug()<<"bonnnn";
    return query.exec();

}

QSqlQueryModel *Clients:: afficher_choix(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

     if(choix=="références décroissants")
    {
        model->setQuery("SELECT * FROM clients  ORDER BY Ref_c DESC ;");
    }
    else if(choix=="références croissants")
    {
        model->setQuery("SELECT * FROM clients  ORDER BY Ref_c ASC;");
    }
     else if(choix=="Alphabétique")
     {
         model->setQuery("SELECT * FROM clients ORDER BY nom_c;");
     }
    else if (choix=="choisir")
    {
        model->setQuery("SELECT * FROM clients ");
    }


    return model;



}




QSqlQueryModel *Clients:: afficher_recherche(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM clients where  nom_c='"+ch+"' ");

    return model ;
}



QSqlQueryModel *Clients:: afficher_recherche2(QString b)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString tel_string=QString::number(telephone);
     QString ref_string= QString::number(Ref_c);
    model->setQuery("SELECT * FROM clients where Ref_c= '"+b+"' ");

    return model ;
}

QSqlQueryModel *Clients:: afficher_recherche3(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString tel_string=QString::number(telephone);
    model->setQuery("SELECT * FROM clients where telephone= '"+ch+"' ");

    return model ;

}



QSqlQueryModel *Clients::afficher_reference()
{
    QSqlQueryModel * model =new QSqlQueryModel();
          model->setQuery("select Ref_c from clients ");
          return model ;
}

Clients::~Clients()
{

}

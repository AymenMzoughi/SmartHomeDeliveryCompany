#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("data_base");
           db.setUserName("mariem");//inserer nom de l'utilisateur
           db.setPassword("0000");

    /*  db.setDatabaseName("db_smart_HD");
           db.setUserName("zeineb");//inserer nom de l'utilisateur
           db.setPassword("test1");*/
if (db.open())
return true;
    return  false;

}
void Connexion::fermerConnexion()
{db.close();}


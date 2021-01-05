#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{

    /*
    db.setDatabaseName("DB_SmartHomeDeliveryCompany");
    db.setUserName("Aymen");//inserer nom de l'utilisateur
    db.setPassword("123");//inserer mot de passe de cet utilisateur*/

    db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName("db_smart_HD");
           db.setUserName("zeineb");//inserer nom de l'utilisateur
           db.setPassword("test1");
if (db.open())
return true;
    return  false;

}
void Connexion::fermerConnexion()
{db.close();}


#include "connexion.h"
#include <QDebug>
//test tutoriel git
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{

 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("db_smart_HD");
db.setUserName("zeineb");//inserer nom de l'utilisateur
db.setPassword("test1");//inserer mot de passe de cet utilisateur

if (db.open())
return true;
    return  false;

}
void Connexion::fermerConnexion()
{db.close();}

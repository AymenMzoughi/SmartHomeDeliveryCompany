#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("amine");//inserer nom de l'utilisateur
    db.setPassword("test1");//inserer mot de passe de cet utilisateur
   //inserer mot de passe de cet utilisateur
if (db.open())
return true;
    return  false;

}
void Connexion::fermerConnexion()
{db.close();}


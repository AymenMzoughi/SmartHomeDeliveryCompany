#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("Amine");//inserer nom de l'utilisateur
    db.setPassword("test1");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;

    qDebug()<<db.lastError().text();


return test;



}

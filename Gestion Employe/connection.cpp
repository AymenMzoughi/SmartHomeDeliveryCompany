#include "connection.h"
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("DB_SmartHomeDeliveryCompany");
db.setUserName("Aymen");//inserer nom de l'utilisateur
db.setPassword("123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

else
{    qDebug()<<db.lastError().text(); }



    return  test;
}

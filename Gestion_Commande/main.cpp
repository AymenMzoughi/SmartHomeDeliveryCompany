#include"connexion.h"
#include"gestioncommandes.h"
#include <QApplication>
#include <QMessageBox>
#include <QApplication>
#include"commandewin.h"
#include"parking.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     Connexion c;
    bool test=c.createconnect();
 Gestioncommandes w;
    //Parking w;

    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}

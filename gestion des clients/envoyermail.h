#ifndef ENVOYERMAIL_H
#define ENVOYERMAIL_H
#include <QString>
#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtCore/QCoreApplication>

namespace Ui {
class Envoyermail;
}

class Envoyermail : public QDialog
{
    Q_OBJECT

public:
    explicit Envoyermail(QWidget *parent = nullptr);
    ~Envoyermail();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();

private:
    Ui::Envoyermail *ui;
    QStringList files;
};

#endif // ENVOYERMAIL_H

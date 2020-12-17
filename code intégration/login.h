#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql>
#include <QFileInfo>
#include <QDialog>
#include <QMessageBox>
#include"admin.h"
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
   /* void on_pb_clear_clicked();

    void on_pb_login_clicked();*/

    void on_pushButton_clicked();

private:
    Ui::Login *ui;

Admin A;
MainWindow *M;






};

#endif // LOGIN_H

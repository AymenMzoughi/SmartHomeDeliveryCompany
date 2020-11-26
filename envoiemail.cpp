#include "envoiemail.h"
#include "ui_envoiemail.h"

Envoiemail::Envoiemail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Envoiemail)
{
    ui->setupUi(this);
}

Envoiemail::~Envoiemail()
{
    delete ui;
}

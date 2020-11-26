#include "envoiem.h"
#include "ui_envoiem.h"

Envoiem::Envoiem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Envoiem)
{
    ui->setupUi(this);
}

Envoiem::~Envoiem()
{
    delete ui;
}

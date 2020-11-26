#ifndef ENVOIEM_H
#define ENVOIEM_H

#include <QDialog>

namespace Ui {
class Envoiem;
}

class Envoiem : public QDialog
{
    Q_OBJECT

public:
    explicit Envoiem(QWidget *parent = nullptr);
    ~Envoiem();

private:
    Ui::Envoiem *ui;
};

#endif // ENVOIEM_H

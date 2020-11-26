#ifndef ENVOIEMAIL_H
#define ENVOIEMAIL_H

#include <QDialog>

namespace Ui {
class Envoiemail;
}

class Envoiemail : public QDialog
{
    Q_OBJECT

public:
    explicit Envoiemail(QWidget *parent = nullptr);
    ~Envoiemail();

private:
    Ui::Envoiemail *ui;
};

#endif // ENVOIEMAIL_H

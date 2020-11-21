#ifndef MAINWIN_H
#define MAINWIN_H

#include <QDialog>

namespace Ui {
class mainwin;
}

class mainwin : public QDialog
{
    Q_OBJECT

public:
    explicit mainwin(QWidget *parent = nullptr);
    ~mainwin();

private:
    Ui::mainwin *ui;
};

#endif // MAINWIN_H

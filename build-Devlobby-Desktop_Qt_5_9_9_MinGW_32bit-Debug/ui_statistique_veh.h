/********************************************************************************
** Form generated from reading UI file 'statistique_veh.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_VEH_H
#define UI_STATISTIQUE_VEH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Statistique_veh
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Statistique_veh)
    {
        if (Statistique_veh->objectName().isEmpty())
            Statistique_veh->setObjectName(QStringLiteral("Statistique_veh"));
        Statistique_veh->resize(801, 525);
        Statistique_veh->setStyleSheet(QStringLiteral("border-image: url(:/img/img/PageA.png);"));
        label = new QLabel(Statistique_veh);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 100, 91, 31));
        label->setStyleSheet(QLatin1String("couleur:rgb(0, 6, 255);\n"
""));
        label_2 = new QLabel(Statistique_veh);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(700, 140, 71, 41));
        label_2->setStyleSheet(QStringLiteral("couleur:rgb(60, 251, 42);"));
        label_3 = new QLabel(Statistique_veh);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(690, 190, 91, 41));
        label_3->setStyleSheet(QStringLiteral("couleur:rgb(97, 109, 0);"));

        retranslateUi(Statistique_veh);

        QMetaObject::connectSlotsByName(Statistique_veh);
    } // setupUi

    void retranslateUi(QDialog *Statistique_veh)
    {
        Statistique_veh->setWindowTitle(QApplication::translate("Statistique_veh", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Statistique_veh", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#5500ff;\">Camion</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Statistique_veh", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#00ff00;\">Moto</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Statistique_veh", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#aaaa00;\">Tricyle</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Statistique_veh: public Ui_Statistique_veh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_VEH_H

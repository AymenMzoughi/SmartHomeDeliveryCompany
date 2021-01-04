/********************************************************************************
** Form generated from reading UI file 'envoyermail.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVOYERMAIL_H
#define UI_ENVOYERMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnvoyerMail
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_8;
    QLineEdit *server;
    QLabel *label_3;
    QLineEdit *rcpt;
    QPlainTextEdit *msg;
    QLineEdit *uname;
    QLabel *label_5;
    QPushButton *browseBtn;
    QLineEdit *file;
    QPushButton *sendBtn;
    QPushButton *exitBtn;
    QLineEdit *paswd;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *port;
    QLabel *label_4;
    QLabel *label_2;
    QComboBox *subject;

    void setupUi(QDialog *EnvoyerMail)
    {
        if (EnvoyerMail->objectName().isEmpty())
            EnvoyerMail->setObjectName(QStringLiteral("EnvoyerMail"));
        EnvoyerMail->resize(673, 680);
        groupBox = new QGroupBox(EnvoyerMail);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 661, 641));
        groupBox->setStyleSheet(QStringLiteral("background-color:rgb(226, 226, 226);"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 81, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 270, 81, 22));
        label_8->setFont(font);
        server = new QLineEdit(groupBox);
        server->setObjectName(QStringLiteral("server"));
        server->setGeometry(QRect(170, 20, 395, 41));
        server->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        server->setReadOnly(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 110, 71, 20));
        label_3->setFont(font);
        rcpt = new QLineEdit(groupBox);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(170, 180, 395, 41));
        rcpt->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        msg = new QPlainTextEdit(groupBox);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(170, 300, 395, 175));
        msg->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        uname = new QLineEdit(groupBox);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setGeometry(QRect(170, 100, 395, 41));
        uname->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 198, 71, 20));
        label_5->setFont(font);
        browseBtn = new QPushButton(groupBox);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(470, 260, 91, 41));
        browseBtn->setStyleSheet(QLatin1String("background-color: black	;\n"
"  border: none;\n"
"  color: white;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        file = new QLineEdit(groupBox);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(170, 260, 291, 41));
        file->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        file->setReadOnly(true);
        sendBtn = new QPushButton(groupBox);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(214, 492, 101, 41));
        sendBtn->setStyleSheet(QLatin1String("background-color: black	;\n"
"  border: none;\n"
"  color: white;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        exitBtn = new QPushButton(groupBox);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(370, 490, 101, 41));
        exitBtn->setStyleSheet(QLatin1String("background-color: #8B0000	;\n"
"  border: none;\n"
"  color: white;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        paswd = new QLineEdit(groupBox);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setGeometry(QRect(170, 140, 395, 41));
        paswd->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        paswd->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 229, 51, 31));
        label_6->setFont(font);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 310, 61, 22));
        label_7->setFont(font);
        port = new QLineEdit(groupBox);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(170, 60, 395, 41));
        port->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        port->setReadOnly(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 150, 61, 31));
        label_4->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 70, 81, 20));
        label_2->setFont(font);
        subject = new QComboBox(groupBox);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(170, 220, 391, 41));
        subject->setStyleSheet(QLatin1String("background-color: white	;\n"
"  border: none;\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"font-family:calibri;\n"
"  display: inline-block;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));

        retranslateUi(EnvoyerMail);

        QMetaObject::connectSlotsByName(EnvoyerMail);
    } // setupUi

    void retranslateUi(QDialog *EnvoyerMail)
    {
        EnvoyerMail->setWindowTitle(QApplication::translate("EnvoyerMail", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("EnvoyerMail", "Smtp-server:", Q_NULLPTR));
        label_8->setText(QApplication::translate("EnvoyerMail", "Attachment:", Q_NULLPTR));
        server->setText(QApplication::translate("EnvoyerMail", "smtp.gmail.com", Q_NULLPTR));
        label_3->setText(QApplication::translate("EnvoyerMail", "l'assistant:", Q_NULLPTR));
        label_5->setText(QApplication::translate("EnvoyerMail", "le client:", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("EnvoyerMail", "Browse...", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("EnvoyerMail", "Send", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("EnvoyerMail", "Exit", Q_NULLPTR));
        paswd->setInputMask(QString());
        label_6->setText(QApplication::translate("EnvoyerMail", "sujet:", Q_NULLPTR));
        label_7->setText(QApplication::translate("EnvoyerMail", "Message:", Q_NULLPTR));
        port->setText(QApplication::translate("EnvoyerMail", "465", Q_NULLPTR));
        label_4->setText(QApplication::translate("EnvoyerMail", "Password:", Q_NULLPTR));
        label_2->setText(QApplication::translate("EnvoyerMail", "Server port:", Q_NULLPTR));
        subject->clear();
        subject->insertItems(0, QStringList()
         << QApplication::translate("EnvoyerMail", "confirmation d'un achat", Q_NULLPTR)
         << QApplication::translate("EnvoyerMail", "r\303\251ponse \303\240 la r\303\251clamation", Q_NULLPTR)
         << QApplication::translate("EnvoyerMail", "v\303\251rification des coordonn\303\251es ", Q_NULLPTR)
         << QApplication::translate("EnvoyerMail", "mise \303\240 jours des cordonn\303\251es du client", Q_NULLPTR)
         << QApplication::translate("EnvoyerMail", "Etat du dossier du cong\303\251", Q_NULLPTR)
         << QString()
        );
    } // retranslateUi

};

namespace Ui {
    class EnvoyerMail: public Ui_EnvoyerMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVOYERMAIL_H

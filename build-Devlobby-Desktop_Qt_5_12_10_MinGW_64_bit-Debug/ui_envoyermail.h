/********************************************************************************
** Form generated from reading UI file 'envoyermail.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVOYERMAIL_H
#define UI_ENVOYERMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
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
            EnvoyerMail->setObjectName(QString::fromUtf8("EnvoyerMail"));
        EnvoyerMail->resize(673, 680);
        groupBox = new QGroupBox(EnvoyerMail);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 661, 641));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(226, 226, 226);"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 81, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 270, 81, 22));
        label_8->setFont(font);
        server = new QLineEdit(groupBox);
        server->setObjectName(QString::fromUtf8("server"));
        server->setGeometry(QRect(170, 20, 395, 41));
        server->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 110, 71, 20));
        label_3->setFont(font);
        rcpt = new QLineEdit(groupBox);
        rcpt->setObjectName(QString::fromUtf8("rcpt"));
        rcpt->setGeometry(QRect(170, 180, 395, 41));
        rcpt->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        msg->setObjectName(QString::fromUtf8("msg"));
        msg->setGeometry(QRect(170, 300, 395, 175));
        msg->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(170, 100, 395, 41));
        uname->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 198, 71, 20));
        label_5->setFont(font);
        browseBtn = new QPushButton(groupBox);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));
        browseBtn->setGeometry(QRect(470, 260, 91, 41));
        browseBtn->setStyleSheet(QString::fromUtf8("background-color: black	;\n"
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
        file->setObjectName(QString::fromUtf8("file"));
        file->setGeometry(QRect(170, 260, 291, 41));
        file->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(214, 492, 101, 41));
        sendBtn->setStyleSheet(QString::fromUtf8("background-color: black	;\n"
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
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(370, 490, 101, 41));
        exitBtn->setStyleSheet(QString::fromUtf8("background-color: #8B0000	;\n"
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
        paswd->setObjectName(QString::fromUtf8("paswd"));
        paswd->setGeometry(QRect(170, 140, 395, 41));
        paswd->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 229, 51, 31));
        label_6->setFont(font);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 310, 61, 22));
        label_7->setFont(font);
        port = new QLineEdit(groupBox);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(170, 60, 395, 41));
        port->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 150, 61, 31));
        label_4->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 70, 81, 20));
        label_2->setFont(font);
        subject = new QComboBox(groupBox);
        subject->addItem(QString());
        subject->addItem(QString());
        subject->addItem(QString());
        subject->addItem(QString());
        subject->addItem(QString());
        subject->addItem(QString());
        subject->setObjectName(QString::fromUtf8("subject"));
        subject->setGeometry(QRect(170, 220, 391, 41));
        subject->setStyleSheet(QString::fromUtf8("background-color: white	;\n"
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
        EnvoyerMail->setWindowTitle(QApplication::translate("EnvoyerMail", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("EnvoyerMail", "Smtp-server:", nullptr));
        label_8->setText(QApplication::translate("EnvoyerMail", "Attachment:", nullptr));
        server->setText(QApplication::translate("EnvoyerMail", "smtp.gmail.com", nullptr));
        label_3->setText(QApplication::translate("EnvoyerMail", "l'assistant:", nullptr));
        label_5->setText(QApplication::translate("EnvoyerMail", "le client:", nullptr));
        browseBtn->setText(QApplication::translate("EnvoyerMail", "Browse...", nullptr));
        sendBtn->setText(QApplication::translate("EnvoyerMail", "Send", nullptr));
        exitBtn->setText(QApplication::translate("EnvoyerMail", "Exit", nullptr));
        paswd->setInputMask(QString());
        label_6->setText(QApplication::translate("EnvoyerMail", "sujet:", nullptr));
        label_7->setText(QApplication::translate("EnvoyerMail", "Message:", nullptr));
        port->setText(QApplication::translate("EnvoyerMail", "465", nullptr));
        label_4->setText(QApplication::translate("EnvoyerMail", "Password:", nullptr));
        label_2->setText(QApplication::translate("EnvoyerMail", "Server port:", nullptr));
        subject->setItemText(0, QApplication::translate("EnvoyerMail", "confirmation d'un achat", nullptr));
        subject->setItemText(1, QApplication::translate("EnvoyerMail", "r\303\251ponse \303\240 la r\303\251clamation", nullptr));
        subject->setItemText(2, QApplication::translate("EnvoyerMail", "v\303\251rification des coordonn\303\251es ", nullptr));
        subject->setItemText(3, QApplication::translate("EnvoyerMail", "mise \303\240 jours des cordonn\303\251es du client", nullptr));
        subject->setItemText(4, QApplication::translate("EnvoyerMail", "Etat du dossier du cong\303\251", nullptr));
        subject->setItemText(5, QString());

    } // retranslateUi

};

namespace Ui {
    class EnvoyerMail: public Ui_EnvoyerMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVOYERMAIL_H

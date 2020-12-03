QT       += core gui sql network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cartefidelite.cpp \
    clients.cpp \
    connexion.cpp \
    envoyermail.cpp \
    main.cpp \
    gestionclient.cpp \
    smtp.cpp

HEADERS += \
    cartefidelite.h \
    clients.h \
    connexion.h \
    envoyermail.h \
    gestionclient.h \
    smtp.h

FORMS += \
    envoyermail.ui \
    gestionclient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

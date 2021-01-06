QT      += core gui sql multimedia charts serialport printsupport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    arduino.cpp \
    cartefidelite.cpp \
    clients.cpp \
    colis.cpp \
    commande.cpp \
    commande_colis.cpp \
    conge.cpp \
    connexion.cpp \
    employe.cpp \
    entrepots.cpp \
    envoyermail.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp \
    statistique_veh.cpp \
    vehicule.cpp

HEADERS += \
    admin.h \
    arduino.h \
    cartefidelite.h \
    clients.h \
    colis.h \
    commande.h \
    commande_colis.h \
    conge.h \
    connexion.h \
    employe.h \
    entrepots.h \
    envoyermail.h \
    mainwindow.h \
    smtp.h \
    statistique_veh.h \
    vehicule.h

FORMS += \
    envoyermail.ui \
    mainwindow.ui \
    statistique_veh.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

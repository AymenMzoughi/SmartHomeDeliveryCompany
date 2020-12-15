QT       += core gui sql charts multimedia serialport
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    commande.cpp \
    commande_colis.cpp \
    connexion.cpp \
    gestioncommandes.cpp \
    main.cpp \
    commandewin.cpp \
    parking.cpp \
    statistiquev.cpp \
    vehicule.cpp \
    vehiculewin.cpp

HEADERS += \
    arduino.h \
    commande.h \
    commande_colis.h \
    commandewin.h \
    connexion.h \
    gestioncommandes.h \
    parking.h \
    statistiquev.h \
    vehicule.h \
    vehiculewin.h

FORMS += \
    commandewin.ui \
    gestioncommandes.ui \
    parking.ui \
    vehiculewin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

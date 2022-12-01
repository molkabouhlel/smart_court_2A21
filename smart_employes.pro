<<<<<<< HEAD:OneDrive/Desktop/smart_court_salle/smart_court_salle.pro
#QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer
#QT       += core gui
QT+= sql
QT       += core printsupport  gui sql network serialport
=======
QT       += core gui printsupport network widgets multimediawidgets axcontainer
QT+=sql
QT       += printsupport
QT       +=charts
QT +=serialport
>>>>>>> c40230be0e5f9b4cadc9f37c6bd820d37153dfd3:smart_employes.pro
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += network
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD:OneDrive/Desktop/smart_court_salle/smart_court_salle.pro
    connection4.cpp \
    main4.cpp \
    mainwindow4.cpp \
    notif.cpp \
    salle.cpp \
    smtp4.cpp

HEADERS += \
    connection4.h \
    mainwindow4.h \
    notif.h \
    salle.h \
    smtp4.h

FORMS += \
    mainwindow4.ui
=======
    arduino.cpp \
    connection.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    statistique.cpp

HEADERS += \
    arduino.h \
    connection.h \
    dialog.h \
    mainwindow.h \
    personnel.h \
    statistique.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    statistique.ui
>>>>>>> c40230be0e5f9b4cadc9f37c6bd820d37153dfd3:smart_employes.pro

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

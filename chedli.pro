QT       += core gui sql
QT       +=sql svg
QT       += core printsupport  gui sql network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
TARGET = MyCurl
CONFIG += c++11 console
LIBS += -llibcurl -lcurl -lssl
CONFIG += c++11 staticlib curl
CONFIG += console
LIBS += -L C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib -llibcurl
LIBS +=C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libcurl.a
INCLUDEPATH += C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib
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
    connection.cpp \
    exportexcel.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcodegen.cpp \
    stmp.cpp \
    suspet.cpp \
    twilio.cpp

HEADERS += \
    connection.h \
    exportexcel.h \
    mainwindow.h \
    qr.h \
    qrcodegen.hpp \
    stmp.h \
    suspet.h \
    twilio.h \
    type_conversion.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ~/../../usr/include
RESOURCES += \
    icon.qrc \
    ph.qrc

DISTFILES += \
    sms.py

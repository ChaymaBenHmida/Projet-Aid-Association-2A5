QT       += core gui
QT += charts
QT += widgets
CONFIG += c++11
QT+=sql
QT  += printsupport
QT       += core gui sql printsupport
QT       += serialport
QT       += core gui multimedia multimediawidgets
TARGET = Atelier_Connexion
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=console

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
    arduino1.cpp \
    chat.cpp \
    chat2.cpp \
    connection.cpp \
    depenses.cpp \
    historiquec.cpp \
    history.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    notifications.cpp \
    recherchc.cpp \
    slidingstackedwidget.cpp \
    dons.cpp \
    historique.cpp \
    activite.cpp \
    arduino.cpp \
    excel.cpp \
    handicape.cpp \
    notification.cpp \
    rechercher.cpp \
    employes.cpp\

HEADERS += \
    arduino1.h \
    chat.h \
    chat2.h \
    connection.h \
    depenses.h \
    historiquec.h \
    history.h \
    login.h \
    mainwindow.h \
    recherchc.h \
    slidingstackedwidget.h \
    dons.h \
    historique.h \
    activite.h \
    notification.h \
    arduino.h \
    excel.h \
    handicape.h \
    rechercher.h \
    employes.h\

FORMS += \
    chat.ui \
    chat2.ui \
    login.ui \
    mainwindow.ui\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    notification.qrc \
    traduction.qrc

DISTFILES += \
    SlidingStackedWidget.pri \

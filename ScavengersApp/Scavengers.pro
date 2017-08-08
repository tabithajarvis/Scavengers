#-------------------------------------------------
#
# Project created by QtCreator 2017-07-28T16:27:28
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scavengers
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        main_window.cpp \
    deck.cpp \
    client.cpp \
    card_widget.cpp

HEADERS += \
        main_window.h \
    deck.h \
    client.h \
    player.h \
    card_widget.h

FORMS += \
        main_window.ui

RESOURCES += \
    resources.qrc

INCLUDEPATH += ../ScavengersLib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/release/ -lScavengersLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug/ -lScavengersLib
else:unix: LIBS += -L$$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/ -lScavengersLib

INCLUDEPATH += $$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug
DEPENDPATH += $$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug

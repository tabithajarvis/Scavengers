QT += network widgets sql

HEADERS       = dialog.h \
                server.h \
                scavengers_thread.h \

SOURCES       = dialog.cpp \
                server.cpp \
                scavengers_thread.cpp \
                main.cpp \

QTPlUGIN += QSQLITE
TEMPLATE = app

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/scavengers_server
INSTALLS += target

DISTFILES += \
    ../json/game_state.json \
    json/card_db.json \
    Scavengers.db

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/release/ -lScavengersLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug/ -lScavengersLib
else:unix: LIBS += -L$$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/ -lScavengersLib

INCLUDEPATH += $$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug
DEPENDPATH += $$PWD/../ScavengersLib/build-ScavengersLib-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug

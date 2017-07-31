QT += network widgets

HEADERS       = dialog.h \
                server.h \
                scavengers_thread.h
SOURCES       = dialog.cpp \
                server.cpp \
                scavengers_thread.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/scavengers_server
INSTALLS += target

DISTFILES += \
    ../json/game_state.json

QT -= gui
QT += network
QT += quick


CONFIG += c++11 console
CONFIG -= app_bundle

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
        card.cpp \
        colorchange.cpp \
        draw.cpp \
        drawfour.cpp \
        drawtwo.cpp \
        game.cpp \
        main.cpp \
        numbered.cpp \
        player.cpp \
        reverse.cpp \
        server.cpp \
        skip.cpp \
        special.cpp \
        wild.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    card.h \
    colorchange.h \
    draw.h \
    drawfour.h \
    drawtwo.h \
    game.h \
    numbered.h \
    player.h \
    reverse.h \
    server.h \
    skip.h \
    special.h \
    wild.h

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    board.cpp \
    main.cpp \
    mainwindow.cpp \
    xo.cpp

HEADERS += \
    board.h \
    mainwindow.h \
    xo.h

FORMS += \
    mainwindow.ui \
    xo.ui

RC_ICONS = toe_circle_icon_145925.ico

DISTFILES += \
    tic-tac-toe_39453.ico

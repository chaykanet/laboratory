QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 debug

contains(QMAKE_CXX, g++|clang++)
{
    QMAKE_CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer -g -Wall -Werror -Wpedantic
    QMAKE_LFLAGS += -fsanitize=address
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actions.cpp \
    drawFigure.cpp \
    edge.cpp \
    edges.cpp \
    figure.cpp \
    handler.cpp \
    main.cpp \
    mainwindow.cpp \
    point.cpp \
    points.cpp

HEADERS += \
    actions.h \
    drawFigure.h \
    edge.h \
    edges.h \
    error.h \
    figure.h \
    handler.h \
    mainwindow.h \
    point.h \
    points.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

TEMPLATE = app
CONFIG -= app_bundle
CONFIG += qt
QT += core charts
CONFIG += c++17

SOURCES += \
        chart.cpp \
        diffequal.cpp \
        gauss.cpp \
        main.cpp \
        point.cpp \
        squareapprox.cpp

HEADERS += \
    chart.h \
    diffequal.h \
    gauss.h \
    point.h \
    squareapprox.h

DISTFILES += \
    3dshow.py \
    data_1d \
    data_1d_1 \
    data_2_1D \
    data_2d \
    test

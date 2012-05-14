#-------------------------------------------------
#
# Project created by QtCreator 2012-05-01T14:55:45
#
#-------------------------------------------------

QT       += core gui network

TARGET = cll12-Pong
TEMPLATE = app


SOURCES += main.cpp\
        pong.cpp \
    serveurtcp.cpp \
    threadjoueurs.cpp

HEADERS  += pong.h \
    serveurtcp.h \
    threadjoueurs.h

FORMS    += pong.ui

OTHER_FILES += \
    readmeServeur.txt \
    QtPongdiagramB.jpg \
    QtPongdiagramA.jpg

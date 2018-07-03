#-------------------------------------------------
#
# Project created by QtCreator 2018-05-27T13:42:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MIDE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        fileinterface.cpp \
        source.cpp \
        buckaroo/official/leethomason/tinyxml2/tinyxml2.cpp \
    mainwindow.cpp \
    sourcenode.cpp \
    remotedialog.cpp \
    parser.cpp \
    sources.cpp \
    mideexception.cpp

FORMS += \
    mainwindow.ui \
    remotedialog.ui \
    sources.ui

HEADERS += \
    fileinterface.h \
    source.h \
    buckaroo/official/leethomason/tinyxml2/tinyxml2.h \
    mainwindow.h \
    sourcenode.h \
    remotedialog.h \
    parser.h \
    sources.h \
    mideexception.h

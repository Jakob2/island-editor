#-------------------------------------------------
#
# Project created by QtCreator 2017-10-14T11:22:35
#
#-------------------------------------------------

QT       += core gui opengl sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = island_editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    world.cpp \
    gui.cpp \
    tilemap.cpp \
    db.cpp \
    mouseray.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    world.h \
    general.h \
    gui.h \
    tilemap.h \
    db.h \
    mouseray.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGLU

QMAKE_CXXFLAGS += -std=c++11

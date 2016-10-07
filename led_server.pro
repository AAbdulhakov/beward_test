#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T22:10:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = led_server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    led_widget.cpp \
    fifo_reader.cpp

HEADERS  += mainwindow.h \
    led_widget.h \
    fifo_reader.h

FORMS    += mainwindow.ui

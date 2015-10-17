#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T19:11:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProgressBarThread
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Top.cpp \
    Child.cpp \
    PushButton.cpp \
    ProgressBar.cpp \
    Thread.cpp \
    StartDialog.cpp \
    ProgressDelegate.cpp \
    MilisecondsDelegate.cpp

HEADERS  += MainWindow.h \
    Top.h \
    Child.h \
    PushButton.h \
    ProgressBar.h \
    Thread.h \
    StartDialog.h \
    ProgressDelegate.h \
    MilisecondsDelegate.h

FORMS    += MainWindow.ui \
    StartDialog.ui

QMAKE_CXXFLAGS += -std=gnu++14

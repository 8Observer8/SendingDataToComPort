#-------------------------------------------------
#
# Project created by QtCreator 2014-10-21T22:04:53
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SendingDataToComPort
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    SettingsDialog.cpp \
    Sender.cpp

HEADERS  += MainWindow.h \
    SettingsDialog.h \
    Sender.h \
    PortError.h \
    PortOpenError.h \
    PortSendDataError.h

FORMS    += MainWindow.ui \
    SettingsDialog.ui

#-------------------------------------------------
#
# Project created by QtCreator 2018-11-23T21:41:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WiFiLinkCalc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QIniFile.cpp \
    DlgConfig.cpp \
    QAntennaGainCB.cpp \
    QAntennaGainTable.cpp \
    QFrequencyCB.cpp

HEADERS  += mainwindow.h \
    QIniFile.h \
    DlgConfig.h \
    AntennaGain.h \
    FrequencyPIRE.h

FORMS    += mainwindow.ui \
    DlgConfig.ui

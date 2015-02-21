target.files = GARVIS_CM
target.path = /home/debian
INSTALLS = target
#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:23:34
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++0x
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GARVIS_CM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    BlackLib/v2_0/BlackADC.cpp \
    BlackLib/v2_0/BlackCore.cpp \
    BlackLib/v2_0/BlackGPIO.cpp \
    BlackLib/v2_0/BlackI2C.cpp \
    BlackLib/v2_0/BlackPWM.cpp \
    BlackLib/v2_0/BlackSPI.cpp \
    BlackLib/v2_0/BlackUART.cpp \
    bb_uart.cpp

HEADERS  += mainwindow.h \
    BlackLib/v2_0/BlackADC.h \
    BlackLib/v2_0/BlackCore.h \
    BlackLib/v2_0/BlackDef.h \
    BlackLib/v2_0/BlackErr.h \
    BlackLib/v2_0/BlackGPIO.h \
    BlackLib/v2_0/BlackI2C.h \
    BlackLib/v2_0/BlackLib.h \
    BlackLib/v2_0/BlackPWM.h \
    BlackLib/v2_0/BlackSPI.h \
    BlackLib/v2_0/BlackUART.h \
    bb_uart.h

FORMS    += mainwindow.ui \
    tutorial.ui

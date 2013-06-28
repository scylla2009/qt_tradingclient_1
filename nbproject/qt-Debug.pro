# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = qt_tradingclient_1
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui opengl
SOURCES += MainWindow.cpp MessageProcessor.cpp main.cpp MarketData.cpp ReqMktDepthGUI.cpp PosixClient.cpp GUIMarketData.cpp ReqMktDataGUI.cpp
HEADERS += MarketData.h ui_reqMktDataGUI.h PosixClient.h ui_reqMktDepthGUI.h ProcessMsgClass.h ReqMktDataGUI.h GUIMarketData.h MainWindow.h IB_events.h ui_MainWindow.h MessageProcessor.h ReqMktDepthGUI.h
FORMS += ReqMktDepthGUI.ui MainWindow.ui ReqMktDataGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += DEBUG HAVE_CONFIG_H IB_USE_STD_STRING _GNU_SOURCE 
INCLUDEPATH += ../twsapi/PosixSocketClient/src ../twsapi/Shared ../twsapi ../twsapi/PosixSocketClient /usr/include/boost /opt/Qt5.0.1/5.0.1/gcc_64/include 
LIBS += -ltwsapi -lQuantLib -lpthread-2.15  

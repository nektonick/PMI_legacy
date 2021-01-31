TEMPLATE     = app
SOURCES	     = main.cpp 
CONFIG       += console
QT           -= gui

macx: CONFIG  -= app_bundle
windows:TARGET = ../LibraryInfo

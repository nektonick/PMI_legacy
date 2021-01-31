TEMPLATE     = app
SOURCES	     = main.cpp 
QT           += network
CONFIG       += console

macx: CONFIG  -= app_bundle
windows:TARGET = ../TcpServer

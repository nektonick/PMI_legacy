TEMPLATE      = app
QT           += xml
SOURCES       = main.cpp 

CONFIG   += console

macx: CONFIG  -= app_bundle
windows: TARGET  = ../XmlSAXRead




TEMPLATE      = app
QT           += xmlpatterns
SOURCES       = main.cpp 
CONFIG   += console

macx: CONFIG  -= app_bundle
windows: TARGET  = ../XQuery


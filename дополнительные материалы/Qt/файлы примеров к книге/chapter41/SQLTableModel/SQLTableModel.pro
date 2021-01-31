TEMPLATE     = app
QT          += widgets sql
SOURCES      = main.cpp
macx: CONFIG  -= app_bundle
windows:TARGET = ../SQLTableModel

TEMPLATE      = app
QT          += sql
SOURCES	      = main.cpp
CONFIG   += console
macx: CONFIG   -= app_bundle
windows: TARGET  = ../SQL

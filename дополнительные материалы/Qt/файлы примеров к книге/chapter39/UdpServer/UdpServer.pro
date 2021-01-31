TEMPLATE     = app
SOURCES	     = main.cpp \
               UdpServer.cpp
QT          += widgets network
HEADERS      = UdpServer.h
windows:TARGET = ../UdpServer
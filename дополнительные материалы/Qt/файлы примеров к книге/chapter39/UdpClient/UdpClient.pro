TEMPLATE     = app
QT          += widgets network
SOURCES	     = main.cpp \
               UdpClient.cpp
HEADERS      = UdpClient.h
windows:TARGET = ../UdpClient


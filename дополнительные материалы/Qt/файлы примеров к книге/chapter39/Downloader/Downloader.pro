TEMPLATE     = app
QT          += widgets network
SOURCES	     = main.cpp \
               Downloader.cpp \
               DownloaderGui.cpp
HEADERS      = Downloader.h \
               DownloaderGui.h 
windows:TARGET = ../Downloader


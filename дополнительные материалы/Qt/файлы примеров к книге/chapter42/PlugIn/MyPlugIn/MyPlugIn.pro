TEMPLATE = lib
CONFIG   += plugin
QT       -= gui
mac {
DESTDIR  = ../MyApplication.app/Contents/plugins
}
else {
DESTDIR  = ../plugins
}
SOURCES  = MyPlugin.cpp
HEADERS  = MyPlugin.h \
           ../Application/interfaces.h 
TARGET   = myplugin


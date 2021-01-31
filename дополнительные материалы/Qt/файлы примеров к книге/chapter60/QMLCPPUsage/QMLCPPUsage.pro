TEMPLATE = app

QT += quick qml widgets quickwidgets

RESOURCES += qml.qrc 
SOURCES += main.cpp \
           MyWidget.cpp
HEADERS += MyWidget.h

windows:TARGET = ../QMLCPPUsage



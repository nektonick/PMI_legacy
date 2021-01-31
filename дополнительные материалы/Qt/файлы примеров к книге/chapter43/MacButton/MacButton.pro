TEMPLATE = app
QT       += widgets
TARGET   = MacButton

macx {
 HEADERS += MacButton.h
 OBJECTIVE_SOURCES += MacButton.mm
 LIBS += -framework Cocoa
}

SOURCES += main.cpp 




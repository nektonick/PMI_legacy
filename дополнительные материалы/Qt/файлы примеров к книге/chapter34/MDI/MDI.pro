TEMPLATE	= app
QT          += widgets
HEADERS		= DocWindow.h \
                  MDIProgram.h                 
SOURCES		= DocWindow.cpp \
                  MDIProgram.cpp \
                  main.cpp 
RESOURCES       = resource.qrc
windows:TARGET	= ../MDI

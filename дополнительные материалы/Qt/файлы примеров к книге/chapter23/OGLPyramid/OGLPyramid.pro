TEMPLATE     = app
QT          += widgets
HEADERS      = OGLPyramid.h
SOURCES	     = OGLPyramid.cpp \
               main.cpp

windows {
LIBS += -lopengl32
TARGET = ../OGLPyramid
}


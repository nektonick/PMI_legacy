TEMPLATE     = app
QT          += widgets
HEADERS      = OGLQuad.h
SOURCES	     = OGLQuad.cpp \
               main.cpp

windows {
LIBS += -lopengl32
TARGET = ../OGLQuad
}

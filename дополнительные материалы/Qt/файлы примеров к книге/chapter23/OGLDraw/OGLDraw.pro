TEMPLATE      = app
QT          += widgets
HEADERS       = OGLDraw.h
SOURCES       = OGLDraw.cpp \
                main.cpp
windows {
LIBS += -lopengl32
TARGET = ../OGLDraw
}


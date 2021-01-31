// ======================================================================
//  OGLQuad.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QOpenGLFunctions>
#include "OGLQuad.h"

// ----------------------------------------------------------------------
OGLQuad::OGLQuad(QWidget* pwgt/*= 0*/) : QOpenGLWidget(pwgt) 
{
}

// ----------------------------------------------------------------------
/*virtual*/void OGLQuad::initializeGL()
{
   QOpenGLFunctions* pFunc = 
       QOpenGLContext::currentContext()->functions();
   pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLQuad::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glOrtho(0, 100, 100, 0, -1, 1); 
}

// ----------------------------------------------------------------------
/*virtual*/void OGLQuad::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); 
        glVertex2f(0, 100);

        glColor3f(0, 1, 0);
        glVertex2f(100, 100);

        glColor3f(0, 0, 1);
        glVertex2f(100, 0);

        glColor3f(1, 1, 1);
        glVertex2f(0, 0);
    glEnd();
}

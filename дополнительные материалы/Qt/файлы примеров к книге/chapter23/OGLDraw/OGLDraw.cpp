// ======================================================================
//  OGLDraw.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QOpenGLFunctions>
#include <math.h>
#include "OGLDraw.h"

// ----------------------------------------------------------------------
OGLDraw::OGLDraw(QWidget* pwgt/*= 0*/) : QOpenGLWidget(pwgt) 
{
}

// ----------------------------------------------------------------------
/*virtual*/void OGLDraw::initializeGL()
{
    QOpenGLFunctions* pFunc = 
        QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLDraw::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glOrtho(0, 400, 200, 0, -1, 1); 
}

// ----------------------------------------------------------------------
/*virtual*/void OGLDraw::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw(0, 0, GL_POINTS);
    draw(100, 0, GL_LINES);
    draw(200, 0, GL_LINE_STRIP);
    draw(300, 0, GL_LINE_LOOP);

    draw(0, 100, GL_TRIANGLE_STRIP);
    draw(100, 100, GL_POLYGON);
    draw(200, 100, GL_QUADS);
    draw(300, 100, GL_TRIANGLES);
}

// ----------------------------------------------------------------------
void OGLDraw::draw(int xOffset, int yOffset, GLenum type)
{
    int n = 8;

    glPointSize(2);
    glBegin(type);
        glColor3f(0, 0, 0);
        for (int i = 0; i < n; ++i) {
            float fAngle = 2 * 3.14 * i / n;
            int   x      = (int)(50 + cos(fAngle) * 40 + xOffset);
            int   y      = (int)(50 + sin(fAngle) * 40 + yOffset);
            glVertex2f(x, y);
        }
    glEnd();
}

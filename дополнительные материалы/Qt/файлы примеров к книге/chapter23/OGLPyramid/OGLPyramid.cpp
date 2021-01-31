// ======================================================================
//  OGLPyramid.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QOpenGLFunctions>
#include <QtGui>
#include "OGLPyramid.h"

// ----------------------------------------------------------------------
OGLPyramid::OGLPyramid(QWidget* pwgt/*= 0*/) : QOpenGLWidget(pwgt) 
                                             , m_xRotate(0)
                                             , m_yRotate(0)
{
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::initializeGL()
{
    QOpenGLFunctions* pFunc = 
        QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nPyramid = createPyramid(1.2f);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);

    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);

    glCallList(m_nPyramid);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::mousePressEvent(QMouseEvent* pe)
{
    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::mouseMoveEvent(QMouseEvent* pe)
{
    m_xRotate += 180 * (GLfloat)(pe->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(pe->x() - m_ptPosition.x()) / width();
    update();

    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
GLuint OGLPyramid::createPyramid(GLfloat fSize/*=1.0f*/)
{
    GLuint n = glGenLists(1);

    glNewList(n, GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
            glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
            glVertex3f(0.0, fSize, 0.0);
            glVertex3f(-fSize, -fSize, fSize);
            glVertex3f(fSize, -fSize, fSize);
            glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
            glVertex3f(fSize, -fSize, -fSize);
            glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
            glVertex3f(-fSize, -fSize, -fSize);
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            glVertex3f(-fSize, -fSize, fSize);
        glEnd();
    
        glBegin(GL_QUADS);
            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-fSize, -fSize, fSize);
            glVertex3f(fSize, -fSize, fSize);
            glVertex3f(fSize, -fSize, -fSize);
            glVertex3f(-fSize, -fSize, -fSize);
        glEnd();
    glEndList();

    return n;
}

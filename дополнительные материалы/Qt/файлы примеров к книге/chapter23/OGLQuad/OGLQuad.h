// ======================================================================
//  OGLQuad.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QOpenGLWidget>

// ======================================================================
class OGLQuad : public QOpenGLWidget {
protected:
    virtual void initializeGL(                       );
    virtual void resizeGL    (int nWidth, int nHeight);
    virtual void paintGL     (                       );

public:
    OGLQuad(QWidget* pwgt = 0);
};

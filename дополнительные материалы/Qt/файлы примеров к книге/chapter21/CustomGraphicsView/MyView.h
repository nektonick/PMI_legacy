// ======================================================================
//  MyView.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QGraphicsView>

// ======================================================================
class MyView: public QGraphicsView {
Q_OBJECT
public:
    MyView(QGraphicsScene* pScene, QWidget* pwgt = 0) 
        : QGraphicsView(pScene, pwgt)
    {
    }

public slots:
    void slotZoomIn()
    {
        scale(1.1, 1.1);
    }

    void slotZoomOut()
    {
        scale(1 / 1.1, 1 / 1.1);
    }

    void slotRotateLeft()
    {
        rotate(-5);
    }

    void slotRotateRight()
    {
        rotate(5);
    }
};

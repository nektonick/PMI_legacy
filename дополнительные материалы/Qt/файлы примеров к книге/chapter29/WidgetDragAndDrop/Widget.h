// ======================================================================
//  Widget.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QPoint>
#include <QLabel>

// ======================================================================
class Widget : public QLabel {
Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag();

protected:
    virtual void mousePressEvent(QMouseEvent*    );
    virtual void mouseMoveEvent (QMouseEvent*    );
    virtual void dragEnterEvent (QDragEnterEvent*);
    virtual void dropEvent      (QDropEvent*     );

public:
    Widget(QWidget* pwgt = 0);
};


// ======================================================================
//  MouseObserver.h --
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

// ======================================================================
class MouseObserver : public QLabel {
public:
    MouseObserver(QWidget* pwgt = 0); 

protected:
    virtual void mousePressEvent  (QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent   (QMouseEvent* pe);

    void    dumpEvent     (QMouseEvent* pe, const QString& strMessage);
    QString modifiersInfo (QMouseEvent* pe                           );
    QString buttonsInfo   (QMouseEvent* pe                           );
};


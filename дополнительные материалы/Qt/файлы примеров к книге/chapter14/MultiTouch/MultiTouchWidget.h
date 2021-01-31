// ======================================================================
//  MultiTouchWidget.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>

// ======================================================================
class MultiTouchWidget : public QWidget {
private:
    QList<QColor>                  m_lstCols;
    QList<QTouchEvent::TouchPoint> m_lstTps;

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual bool event     (QEvent*     );

public:
    MultiTouchWidget(QWidget* pwgt = 0);
};

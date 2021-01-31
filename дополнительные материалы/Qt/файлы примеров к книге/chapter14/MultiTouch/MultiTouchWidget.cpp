// ======================================================================
//  MultiTouchWidget.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtGui>
#include "MultiTouchWidget.h"

// ----------------------------------------------------------------------
MultiTouchWidget::MultiTouchWidget(QWidget* pwgt/*= 0*/) : QWidget(pwgt)
{
    setAttribute(Qt::WA_AcceptTouchEvents);

    m_lstCols << Qt::cyan << Qt::green << Qt::blue << Qt::black 
              << Qt::red << Qt::magenta << Qt::darkYellow 
              << Qt::gray << Qt::darkCyan << Qt::darkBlue;
}

// ----------------------------------------------------------------------
/*virtual*/ void MultiTouchWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int nColsCount = m_lstCols.count();
    foreach (QTouchEvent::TouchPoint tp, m_lstTps) {
        switch (tp.state()) {
        case Qt::TouchPointStationary:
            continue;
        default:
            QColor c(m_lstCols.at(tp.id() % nColsCount));
            painter.setPen(c);
            painter.setBrush(c);

            QRectF r1(tp.pos(), QSize(20, 20));
            QRectF r2(tp.startPos(), QSize(20, 20));
            painter.drawEllipse(r1.translated(-10, -10));
            painter.drawEllipse(r2.translated(-10, -10));

            painter.drawLine(tp.pos(), tp.startPos());
        }
    }
}

// ----------------------------------------------------------------------
/*virtual*/ bool MultiTouchWidget::event(QEvent* pe)
{
    switch (pe->type()) {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
        {
        QTouchEvent* pte = static_cast<QTouchEvent*>(pe);
        m_lstTps = pte->touchPoints();
        update();
        }
    default:
        return QWidget::event(pe);
    }
    return true;
}

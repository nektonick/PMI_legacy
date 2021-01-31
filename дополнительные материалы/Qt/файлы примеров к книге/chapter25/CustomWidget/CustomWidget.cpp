// ======================================================================
//  CustomWidget.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtGui>
#include "CustomWidget.h"

// ----------------------------------------------------------------------
CustomWidget::CustomWidget(QWidget* pwgt/*= 0*/) : QFrame(pwgt) 
                                                 , m_nProgress(0)
{
    setLineWidth(3);
    setFrameStyle(Box | Sunken);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
}

// ----------------------------------------------------------------------
/*virtual*/ void CustomWidget::paintEvent(QPaintEvent*) 
{
    QPainter        painter(this);
    QLinearGradient gradient(0, 0, width(), height());
    float           f = m_nProgress / 100.0f;

    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(f, Qt::green);

    painter.fillRect(rect(), Qt::black);
    painter.setBrush(gradient);
    painter.drawRect(0, 0, (int)(width() * f), height());

    painter.setPen(QPen(Qt::green));
    QString str = QString().setNum(m_nProgress) + "%";
    painter.drawText(rect(), Qt::AlignCenter, str);

    drawFrame(&painter);
}

// ----------------------------------------------------------------------
void CustomWidget::slotSetProgress(int n)
{
    m_nProgress = n > 100 ? 100 : n < 0 ? 0 : n;
    repaint();   
    emit progressChanged(m_nProgress);
}

// ----------------------------------------------------------------------
/*virtual*/ QSize CustomWidget::sizeHint() const
{
    return QSize(200, 30);
}


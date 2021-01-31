// ======================================================================
//  Ellipse.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QPainter>
#include "Ellipse.h"

// ----------------------------------------------------------------------
Ellipse::Ellipse(QQuickItem* pqi /*= 0*/) : QQuickPaintedItem(pqi)
                                          , m_color(Qt::black)
{ 
}

// ----------------------------------------------------------------------
void Ellipse::paint(QPainter* ppainter)
{ 
    ppainter->setRenderHint(QPainter::Antialiasing, true);
    ppainter->setBrush(QBrush(colorValue()));
    ppainter->setPen(Qt::NoPen);
    ppainter->drawEllipse(boundingRect());
}

// ----------------------------------------------------------------------
QColor Ellipse::colorValue() const
{
    return m_color;
}

// ----------------------------------------------------------------------
void Ellipse::setColorValue(const QColor& col)
{
    m_color  = col;
}

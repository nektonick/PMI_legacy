// ======================================================================
//  Calculation.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QQuickPaintedItem>

class QPainter;

// ======================================================================
class Ellipse : public QQuickPaintedItem {
Q_OBJECT
private:
    Q_PROPERTY(QColor color WRITE  setColorValue
                            READ   colorValue
              )
    QColor m_color;

public:
    Ellipse(QQuickItem* pqi = 0);
    void paint(QPainter* ppainter);

    QColor colorValue   (             ) const;
    void   setColorValue(const QColor&);
};


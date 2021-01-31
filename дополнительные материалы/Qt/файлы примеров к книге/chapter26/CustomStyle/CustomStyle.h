// ======================================================================
//  CustomStyle.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

class QPainter;

// ======================================================================
class CustomStyle : public QCommonStyle {
public:
    virtual void polish  (QWidget* pwgt);
    virtual void unpolish(QWidget* pwgt);

    virtual void drawPrimitive(      PrimitiveElement elem, 
                               const QStyleOption*    popt,
                                     QPainter*        ppainter, 
                               const QWidget*         pwgt = 0
                              ) const;
};

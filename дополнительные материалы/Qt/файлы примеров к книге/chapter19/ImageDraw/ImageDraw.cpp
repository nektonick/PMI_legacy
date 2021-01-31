// ======================================================================
//  ImageDraw.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtGui>
#include "ImageDraw.h"

// ----------------------------------------------------------------------
ImageDraw::ImageDraw(QWidget* pwgt/*=0*/) : QWidget(pwgt) 
{
}

// ----------------------------------------------------------------------
/*virtual*/ImageDraw::~ImageDraw()
{
}

// ----------------------------------------------------------------------
/*virtual*/ void ImageDraw::paintEvent(QPaintEvent*) 
{
    QImage   img(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;

    painter.begin(&img);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.eraseRect(rect());
    painter.drawEllipse(0, 0, size().width(), size().height());
    painter.end();

    painter.begin(this);
    painter.drawImage(0, 0, img);
    painter.end();
}

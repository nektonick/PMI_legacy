// ======================================================================
//  MyWidget.h
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
class MyWidget : public QWidget {
    Q_OBJECT
public:
    MyWidget(QWidget* pwgt = 0);
};


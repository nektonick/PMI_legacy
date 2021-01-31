// ======================================================================
//  MouseFilter.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QObject>

// ======================================================================
class MouseFilter : public QObject {
protected:
    virtual bool eventFilter(QObject*, QEvent*);

public:
    MouseFilter(QObject* pobj = 0);

};


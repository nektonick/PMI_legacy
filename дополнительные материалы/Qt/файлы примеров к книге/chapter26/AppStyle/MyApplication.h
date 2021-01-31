// ======================================================================
//  MyApplication.h
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
class MyApplication : public QWidget {
    Q_OBJECT
public:
    MyApplication(QWidget* pwgt = 0);    

public slots:
    void slotChangeStyle(const QString& str);
};


// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QApplication>
#include "Widget.h"

// ----------------------------------------------------------------------
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Widget       wgt1;
    Widget       wgt2;

    wgt1.setWindowTitle("Widget1");
    wgt1.setObjectName("Widget1");
    wgt1.resize(200, 200);
    wgt1.show();

    wgt2.setWindowTitle("Widget2");
    wgt2.setObjectName("Widget2");
    wgt2.resize(200, 200);
    wgt2.show();

    return app.exec();
}

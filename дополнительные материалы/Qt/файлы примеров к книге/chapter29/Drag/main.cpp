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

#include "Drag.h"

// ----------------------------------------------------------------------
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Drag         drag;

    drag.resize(150, 150);
    drag.show();

    return app.exec();
}

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
#include "Drop.h"

// ----------------------------------------------------------------------
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Drop         drop;

    drop.resize(150, 150);
    drop.show();

    return app.exec();
}

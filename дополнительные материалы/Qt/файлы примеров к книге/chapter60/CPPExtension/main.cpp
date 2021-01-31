// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget mw;
    mw.show();

    return app.exec();
}

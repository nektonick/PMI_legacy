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

#ifdef Q_OS_OSX
#include "MacButton.h"
#endif

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

#ifdef Q_OS_OSX
    MacButton cmd;
    cmd.show();
#else
    QLabel label("This example requires Mac OS X");
    label.show();
#endif

    return app.exec();
}



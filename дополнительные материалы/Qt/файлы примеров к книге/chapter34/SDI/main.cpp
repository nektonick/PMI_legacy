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
#include "SDIProgram.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv) 
{
    QApplication app(argc, argv);
    SDIProgram   psdi;

    psdi.setWindowTitle("SDI Program");
    psdi.resize(300, 300);
    psdi.show();

    return app.exec();
}

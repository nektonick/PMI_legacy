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
#include "HelpBrowser.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);  
    HelpBrowser  helpBrowser(":/", "index.htm");

    helpBrowser.resize(450, 350);
    helpBrowser.show();

    return app.exec();
}

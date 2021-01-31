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

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QLabel lbl("<CENTER><A HREF=\"http://www.bhv.ru\">www.bhv.ru</A></CENTER>");

    lbl.setOpenExternalLinks(true);
    lbl.show();

    return app.exec();
}

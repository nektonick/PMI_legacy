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

    QPixmap pix;
    pix.load(":/mira.jpg");

    QLabel lbl;
    lbl.resize(pix.size());
    lbl.setPixmap(pix);

    lbl.show();

    return app.exec();
}

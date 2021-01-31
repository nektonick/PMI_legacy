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
    QLabel       lbl;
    QMovie       mov(":/motion.gif");

    mov.start();

    lbl.setMovie(&mov);
    lbl.resize(mov.frameRect().size());
    lbl.show();

    return app.exec();
}


// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtGui>
#include <QtSvg>

// ----------------------------------------------------------------------
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QSvgWidget svg(":/motion.svg");
    svg.show();

    QObject::connect(svg.renderer(), SIGNAL(repaintNeeded()), 
                     &svg,           SLOT(repaint())
                    );

    return app.exec();
}

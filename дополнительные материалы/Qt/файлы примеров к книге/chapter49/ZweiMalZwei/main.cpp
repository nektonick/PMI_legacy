// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtCore>
#include <QJSEngine>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    
    QJSEngine scriptEngine;
    QJSValue  value = scriptEngine.evaluate("2 * 2");
    qDebug() << value.toInt(); 

    return 0;
}

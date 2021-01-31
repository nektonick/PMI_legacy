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
#include <QJSEngine>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLabel* plbl = new QLabel;

    QJSEngine scriptEngine;
    QJSValue  scriptLbl = scriptEngine.newQObject(plbl);
    scriptEngine.globalObject().setProperty("lbl", scriptLbl);
    scriptEngine.evaluate("lbl.text = 'Hello, JavaScript !'");
    scriptEngine.evaluate("lbl.show()");

    return app.exec();
}

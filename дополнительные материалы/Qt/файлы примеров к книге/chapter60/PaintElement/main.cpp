// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Ellipse.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Ellipse>("com.myinc.Ellipse", 1, 0, "Ellipse");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


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
#include "Calculation.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Calculation>("com.myinc.Calculation", 1, 0, "Calculation");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


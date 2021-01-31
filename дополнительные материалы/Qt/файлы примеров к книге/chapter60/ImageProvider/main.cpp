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
#include "ImageProvider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine eng;
    eng.addImageProvider(QLatin1String("brightness"), new ImageProvider);
    eng.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


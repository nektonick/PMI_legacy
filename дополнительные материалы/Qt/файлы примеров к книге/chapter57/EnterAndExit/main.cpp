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
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView> 
#include <QDir>

// ----------------------------------------------------------------------
int main(int argc, char** argv) 
{
    QGuiApplication app(argc,argv);
    QQuickView      view;
    QFileInfo       fi(app.applicationFilePath());

    app.setApplicationName(fi.baseName());

    view.connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    /*QQmlFileSelector* ps =*/ new QQmlFileSelector(view.engine(), &view);

    view.setSource(QUrl("qrc:/main.qml")); 
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}

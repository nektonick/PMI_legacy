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
#include <QQuickView> 
#include <QQmlContext>
#include <QUrl>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    QQuickView view;

    QUrl urlAssetsPath;
#if defined(Q_OS_IOS)
    urlAssetsPath = QUrl("file://" + qApp->applicationDirPath() + "/");
#elif defined(Q_OS_ANDROID)
    urlAssetsPath = QUrl("assets:/Resources/");
#endif
    view.rootContext()->setContextProperty("assetsPath", urlAssetsPath);
    view.setSource(QUrl("qrc:/main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);

#if defined(Q_OS_IOS)
    view.showFullScreen();
#else
    view.show();
#endif

    return app.exec();
}

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
#include <QQmlComponent>
#include "CppConnection.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv) 
{
    QGuiApplication       app(argc,argv);
    QQmlApplicationEngine eng;
    QQmlComponent         comp(&eng, QUrl("qrc:/main.qml"));
    CppConnection         cc;

    QObject* pobj           = comp.create();
    QObject* pcmdQuitButton = pobj->findChild<QObject*>("QuitButton");
    if (pcmdQuitButton) {
        QObject::connect(pcmdQuitButton, SIGNAL(quitClicked()), 
                         &cc, SLOT(slotQuit())
                        );
    }
    QObject* pcmdInfoButton = pobj->findChild<QObject*>("InfoButton");
    if (pcmdInfoButton) {
        QObject::connect(pcmdInfoButton, SIGNAL(infoClicked(QString)), 
                         &cc, SLOT(slotInfo(QString))
                        );
    } 

    return app.exec();
}

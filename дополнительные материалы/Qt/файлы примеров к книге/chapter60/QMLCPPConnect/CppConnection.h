// ======================================================================
//  CppConnection.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once
#include <QtCore>

// ======================================================================
class CppConnection : public QObject {
Q_OBJECT
public:
    CppConnection(QObject* pobj = 0)
        : QObject(pobj)
    {
    }

public slots:
    void slotQuit()
    {
        qApp->quit();
    }

    void slotInfo(const QString& str)
    {
        qDebug() << str;
    }
};


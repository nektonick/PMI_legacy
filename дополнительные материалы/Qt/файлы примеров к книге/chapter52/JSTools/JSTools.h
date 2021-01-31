// ======================================================================
//  JSTools.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

// ======================================================================
class JSTools : public QObject {
Q_OBJECT
public:
    JSTools(QObject* pobj = 0) : QObject(pobj)
    {
    }

public slots:
    void print(const QString& str)
    {
        qDebug() << str;
    }

    void alert(const QString& strMessage)
    {
        QMessageBox::information(0, "", strMessage);
    }    

    void quitApplication()
    {
        qApp->quit();
    }

    QStringList dirEntryList(const QString& strDir, 
                             const QString& strExt
                            )
    {
        QDir dir(strDir);
        return dir.entryList(strExt.split(" "), QDir::Files);
    }
};



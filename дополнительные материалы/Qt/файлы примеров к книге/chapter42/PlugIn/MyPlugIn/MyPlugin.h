// ======================================================================
//  MyPlugin.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QObject>
#include "../Application/interfaces.h"

// ======================================================================
class MyPlugin : public QObject, public StringInterface {
Q_OBJECT
Q_INTERFACES(StringInterface)
Q_PLUGIN_METADATA(IID "com.mysoft.Application.StringInterface" FILE "stringinterface.json")

private:
    QString oddUpper(const QString& str);

public:
    virtual ~MyPlugin();

    virtual QStringList operations(                              ) const;
    virtual QString     operation (const QString&, const QString&);
};


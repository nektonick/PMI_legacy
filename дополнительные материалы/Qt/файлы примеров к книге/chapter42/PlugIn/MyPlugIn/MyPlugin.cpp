// ======================================================================
//  PlugIn.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtCore>
#include "MyPlugin.h"

// ----------------------------------------------------------------------
QString MyPlugin::oddUpper(const QString& str)
{ 
    QString strTemp;

    for (int i = 0; i < str.length(); ++i) {
        strTemp += (i % 2) ? str.at(i) : str.at(i).toUpper();
    }

    return strTemp;
}

// ----------------------------------------------------------------------
/*virtual*/ MyPlugin::~MyPlugin()
{
}

// ----------------------------------------------------------------------
/*virtual*/ QStringList MyPlugin::operations() const
{
    return QStringList() << "oddUpper" << "lower";
}

// ----------------------------------------------------------------------
/*virtual*/ QString MyPlugin::operation(const QString& strText, 
                                        const QString& strOperation
                                       )
{
    QString strTemp;
    if (strOperation == "oddUpper") {
        strTemp = oddUpper(strText);
    }
    else if (strOperation == "lower") {
        strTemp = strText.toLower();
    }
    else {
        qDebug() << "Unsupported operation";
    }
    return strTemp;
}

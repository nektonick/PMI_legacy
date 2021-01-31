// ======================================================================
//  interfaces.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

class QString;
class QStringList;

// ======================================================================
class StringInterface {
public:
    virtual ~StringInterface() {}

    virtual QStringList operations() const = 0;

    virtual QString operation(const QString& strText, 
                              const QString& strOperation
                             ) = 0;
};

Q_DECLARE_INTERFACE(StringInterface,
                    "com.mysoft.Application.StringInterface"
                   )

// ======================================================================
//  Calculation.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QObject>

// ======================================================================
class Calculation : public QObject {
Q_OBJECT
private:
    Q_PROPERTY(qulonglong input WRITE  setInputValue
                                READ   inputValue
                                NOTIFY inputValueChanged
              )
    Q_PROPERTY(qulonglong result READ   resultValue
                                 NOTIFY resultValueChanged
              )

    qulonglong m_nInput;
    qulonglong m_nResult;

public:
    Calculation(QObject* pobj = 0);

    Q_INVOKABLE qulonglong factorial(const qulonglong& n);

    qulonglong inputValue   (                 ) const;
    void       setInputValue(const qulonglong&);
    qulonglong resultValue  (                 ) const;

signals:
    void inputValueChanged (qulonglong);
    void resultValueChanged(qulonglong);
};


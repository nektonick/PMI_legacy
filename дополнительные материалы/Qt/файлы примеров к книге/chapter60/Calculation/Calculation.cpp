// ======================================================================
//  Calculation.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include "Calculation.h"

// ----------------------------------------------------------------------
Calculation::Calculation(QObject* pobj) : QObject(pobj)
                                        , m_nInput(0)
                                        , m_nResult(1)
{ 
}

// ----------------------------------------------------------------------
qulonglong Calculation::factorial(const qulonglong& n)
{
    return n ? (n * factorial(n - 1)) : 1;
}

// ----------------------------------------------------------------------
qulonglong Calculation::inputValue() const
{
    return m_nInput;
}

// ----------------------------------------------------------------------
qulonglong Calculation::resultValue() const
{
    return m_nResult;
}

// ----------------------------------------------------------------------
void Calculation::setInputValue(const qulonglong& n)
{
    m_nInput  = n;
    m_nResult = factorial(m_nInput);

    emit inputValueChanged(m_nInput);
    emit resultValueChanged(m_nResult);
}


// ======================================================================
//  test.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtTest>
#include "MyClass.h"

// ======================================================================
class Test_MyClass : public QObject {
Q_OBJECT
private slots:
    void min();
    void max();
};

// ----------------------------------------------------------------------
void Test_MyClass::min()
{
    MyClass myClass;
    QCOMPARE(myClass.min(25, 0), 0);
    QCOMPARE(myClass.min(-12, -5), -12);
    QCOMPARE(myClass.min(2007, 2007), 2007);
    QCOMPARE(myClass.min(-12, 5), -12);
}

// ----------------------------------------------------------------------
void Test_MyClass::max()
{
    MyClass myClass;
    QCOMPARE(myClass.max(25, 0), 25);
    QCOMPARE(myClass.max(-12, -5), -5);
    QCOMPARE(myClass.max(2007, 2007), 2007);
    QCOMPARE(myClass.max(-12, 5), 5);
}

QTEST_MAIN(Test_MyClass)
#include "test.moc"

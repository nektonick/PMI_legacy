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
#include <QtWidgets>

// ======================================================================
class Test_QLineEdit : public QObject {
Q_OBJECT
private slots:
    void edit();
};

// ----------------------------------------------------------------------
void Test_QLineEdit::edit()
{
    QLineEdit txt;
    QTest::keyClicks(&txt, "ABCDEFGH");

    QCOMPARE(txt.text(), QString("ABCDEFGH"));
    QVERIFY(txt.isModified());
}

QTEST_MAIN(Test_QLineEdit)
#include "test.moc"

// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtCore>
#include <QtConcurrent/QtConcurrent>

// ----------------------------------------------------------------------
QString myToUpper(const QString& str)
{
    return str.toUpper();
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
 
    QFuture<QString> future = QtConcurrent::run(myToUpper, QString("test"));
    future.waitForFinished();
    qDebug() << future.result();

    return 0;
}


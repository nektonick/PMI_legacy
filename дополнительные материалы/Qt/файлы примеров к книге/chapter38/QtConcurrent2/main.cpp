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
 
    QStringList lst(QStringList() << "one" << "two" << "three");
    QFuture<QString> future = 
         QtConcurrent::mapped(lst.begin(), lst.end(), myToUpper);

    future.waitForFinished();
    qDebug() << future.results();

    return 0;
}



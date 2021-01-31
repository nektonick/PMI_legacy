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
#include <QtNetwork>

// ---------------------------------------------------------------------
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    QTcpSocket       socket;

    socket.connectToHost(QHostAddress::LocalHost, 2424);
    socket.waitForDisconnected();
    qDebug() << socket.readAll();

    return 0;
}


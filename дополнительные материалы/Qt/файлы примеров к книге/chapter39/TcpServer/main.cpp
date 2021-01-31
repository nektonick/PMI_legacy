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

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    QTcpServer       tcpServer;
    int              nPort = 2424;

    if (!tcpServer.listen(QHostAddress::Any, nPort)) {
        qDebug() << "Can't listen on port: " << nPort;
        return 0;
    }

    forever {
        while (tcpServer.waitForNewConnection(60000)) {
        do {
            QTcpSocket* pSocket = tcpServer.nextPendingConnection();
            QString strDateTime =
                QDateTime::currentDateTime()
                  .toString("yyyy.MM.dd hh:mm:ss");
                pSocket->write(strDateTime.toLatin1());
                pSocket->flush();
                qDebug() << "Server date & time:" + strDateTime;
                pSocket->disconnectFromHost();
                if (pSocket->state() == QAbstractSocket::ConnectedState) {
                    pSocket->waitForDisconnected();
                }
                delete pSocket;
            } while (tcpServer.hasPendingConnections());
        }
    }

    return 0;
}


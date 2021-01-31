// ======================================================================
//  UdpServer.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtNetwork>
#include <QtGui>
#include "UdpServer.h"

// ----------------------------------------------------------------------
UdpServer::UdpServer(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpServer");

    m_pudp = new QUdpSocket(this);

    QTimer* ptimer = new QTimer(this);
    ptimer->setInterval(500);
    ptimer->start();
    connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}

// ----------------------------------------------------------------------
void UdpServer::slotSendDatagram()
{
    QByteArray baDatagram;
    QDataStream out(&baDatagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    QDateTime dt = QDateTime::currentDateTime();
    append("Sent:" + dt.toString());
    out << dt;
    m_pudp->writeDatagram(baDatagram, QHostAddress::LocalHost, 2424); 
}


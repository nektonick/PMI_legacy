// ======================================================================
//  UdpClient.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtNetwork>
#include <QtGui>
#include "UdpClient.h"

// ----------------------------------------------------------------------
UdpClient::UdpClient(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("UdpClient");

    m_pudp = new QUdpSocket(this);
    m_pudp->bind(2424);
    connect(m_pudp, SIGNAL(readyRead()), SLOT(slotProcessDatagrams()));    
}

// ----------------------------------------------------------------------
void UdpClient::slotProcessDatagrams()
{
    QByteArray baDatagram;
    do {
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(), baDatagram.size());
    } while(m_pudp->hasPendingDatagrams());

    QDateTime dateTime;
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_3);
    in >> dateTime;
    append("Received:" + dateTime.toString());
}


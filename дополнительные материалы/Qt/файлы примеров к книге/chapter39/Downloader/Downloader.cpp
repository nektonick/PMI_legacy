// ======================================================================
//  Downloader.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtNetwork>
#include "Downloader.h"

// ----------------------------------------------------------------------
Downloader::Downloader(QObject* pobj/*=0*/) : QObject(pobj)
{ 
    m_pnam = new QNetworkAccessManager(this);
    connect(m_pnam, SIGNAL(finished(QNetworkReply*)), 
            this,   SLOT(slotFinished(QNetworkReply*))
           );
}

// ----------------------------------------------------------------------
void Downloader::download(const QUrl& url)
{
    QNetworkRequest request(url);
    QNetworkReply*  pnr = m_pnam->get(request);
    connect(pnr, SIGNAL(downloadProgress(qint64, qint64)), 
            this, SIGNAL(downloadProgress(qint64, qint64))
           );
}

// ----------------------------------------------------------------------
void Downloader::slotFinished(QNetworkReply* pnr)
{
    if (pnr->error() != QNetworkReply::NoError) {
        emit error();
    }
    else {
        emit done(pnr->url(), pnr->readAll());
    }
    pnr->deleteLater();
}

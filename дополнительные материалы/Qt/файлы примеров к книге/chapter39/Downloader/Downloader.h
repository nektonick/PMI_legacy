// ======================================================================
//  Downloader.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

// ======================================================================
class Downloader : public QObject {
Q_OBJECT

private:
    QNetworkAccessManager* m_pnam;

public:
    Downloader(QObject* pobj = 0);

    void download(const QUrl&);

signals:
    void downloadProgress(qint64, qint64                );
    void done            (const QUrl&, const QByteArray&);
    void error           (                              );

private slots:
    void slotFinished(QNetworkReply*);
};


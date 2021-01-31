// ======================================================================
//  DownloaderGui.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>
#include <QUrl>

class Downloader;
class QProgressBar;
class QLineEdit;
class QPushButton;

// ======================================================================
class DownloaderGui : public QWidget {
Q_OBJECT

private:
    Downloader*   m_pdl;
    QProgressBar* m_ppb;
    QLineEdit*    m_ptxt;
    QPushButton*  m_pcmd;

    void showPic(const QString&);

public:
    DownloaderGui(QWidget* pwgt = 0);

private slots:
    void slotGo              (                              );
    void slotError           (                              );
    void slotDownloadProgress(qint64, qint64                );
    void slotDone            (const QUrl&, const QByteArray&);
};


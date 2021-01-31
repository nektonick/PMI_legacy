// ======================================================================
//  ImageProvider.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QObject>
#include <QImage>
#include <QQuickImageProvider>

// ======================================================================
class ImageProvider : public QQuickImageProvider {
private:
    QImage brightness(const QImage& imgOrig, int n);

public:
    ImageProvider();

    QImage requestImage(const QString&, QSize*, const QSize&);
};                                                    

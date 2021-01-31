// ======================================================================
//  CustomWidget.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QFrame>

// ======================================================================
class CustomWidget : public QFrame {
    Q_OBJECT
protected:
    int m_nProgress;

    virtual void paintEvent(QPaintEvent*);

public:
    CustomWidget(QWidget* pwgt = 0);

    virtual QSize sizeHint() const;

signals:
    void progressChanged(int);

public slots:
    void slotSetProgress(int n);
};

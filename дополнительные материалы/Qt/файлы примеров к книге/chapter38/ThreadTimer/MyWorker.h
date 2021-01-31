// ======================================================================
//  MyThread.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

// ======================================================================
class MyWorker : public QObject {
Q_OBJECT
private:
    int     m_nValue;
    QTimer* m_ptimer;

public:
    MyWorker(QObject* pobj = 0) : QObject(pobj)
                                , m_nValue(10)
    {
        m_ptimer = new QTimer(this);

        connect(m_ptimer, SIGNAL(timeout()), SLOT(setNextValue()));
    }

signals:
    void valueChanged(int);
    void finished    (   );

public slots:
    void slotDoWork()
    {
        m_ptimer->start(1000);
    }

private slots:
    void setNextValue()
    {
        emit valueChanged(--m_nValue);

        if(!m_nValue){
            m_ptimer->stop();
            emit finished();
        }
    }
};

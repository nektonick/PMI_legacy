// ======================================================================
//  Clock.h
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
class Clock : public QLabel {
    Q_OBJECT

public:
    Clock(QWidget* pwgt = 0) : QLabel(pwgt)
    {
        QTimer* ptimer = new QTimer(this);
        connect(ptimer, SIGNAL(timeout()), SLOT(slotUpdateDateTime()));
        ptimer->start(500);
        slotUpdateDateTime();
    }

public slots:
    void slotUpdateDateTime()
    {
        QString str = 
            QDateTime::currentDateTime().toString(Qt::SystemLocaleLongDate);
        setText("<H2><CENTER>" + str + "</CENTER></H2>");
    }
};

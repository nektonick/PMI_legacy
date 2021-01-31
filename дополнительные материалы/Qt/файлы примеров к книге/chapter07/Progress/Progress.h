// ======================================================================
//  Progress.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>

class QProgressBar;

// ======================================================================
class Progress : public QWidget {
    Q_OBJECT
private:
    QProgressBar* m_pprb;
    int           m_nStep;

public:
    Progress(QWidget* pobj = 0);

public slots:
    void slotStep ();
    void slotReset();
};

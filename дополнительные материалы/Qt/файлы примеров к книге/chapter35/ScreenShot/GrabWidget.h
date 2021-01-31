// ======================================================================
//  GrabWidget.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>

class QLabel;

// ======================================================================
class GrabWidget : public QWidget {
Q_OBJECT
private:
     QLabel* m_plbl;

public:
    GrabWidget(QWidget* pwgt = 0);

public slots:
    void slotGrabScreen();
};

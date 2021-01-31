// ======================================================================
//  MyForm.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include "ui_MyForm.h"

// ======================================================================
class MyForm : public QWidget, public Ui::MyForm {
    Q_OBJECT

public:
    MyForm(QWidget* pwgt = 0) : QWidget(pwgt)
    {
        setupUi(this);

        connect(m_cmdReset, SIGNAL(clicked()), SLOT(slotReset()));
    }

public slots:
    void slotReset()
    {
        m_sld->setValue(0);
        m_lcd->display(0);
    }
};


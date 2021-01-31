// ======================================================================
//  StartDialog.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>
#include "InputDialog.h"

// ======================================================================
class StartDialog : public QPushButton {
Q_OBJECT
public:
    StartDialog(QWidget* pwgt = 0) : QPushButton("Press Me", pwgt) 
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }

public slots:
    void slotButtonClicked()
    {
        InputDialog* pInputDialog = new InputDialog;    
        if (pInputDialog->exec() == QDialog::Accepted) {
            QMessageBox::information(0, 
                                     "Information", 
                                     "First Name: " 
                                     + pInputDialog->firstName()
                                     + "\nLast Name: " 
                                     + pInputDialog->lastName()
                                    );
        }
        delete pInputDialog;
    } 
};

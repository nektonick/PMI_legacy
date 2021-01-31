// ======================================================================
//  InputDialog.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "InputDialog.h"

// ----------------------------------------------------------------------
InputDialog::InputDialog(QWidget* pwgt/*= 0*/) 
     : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{   
    m_ptxtFirstName = new QLineEdit;
    m_ptxtLastName  = new QLineEdit;

    QLabel* plblFirstName    = new QLabel("&First Name");
    QLabel* plblLastName     = new QLabel("&Last Name");

    plblFirstName->setBuddy(m_ptxtFirstName);
    plblLastName->setBuddy(m_ptxtLastName);

    QPushButton* pcmdOk     = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    //Layout setup
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstName, 0, 0);
    ptopLayout->addWidget(plblLastName, 1, 0);
    ptopLayout->addWidget(m_ptxtFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxtLastName, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2,0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}

// ----------------------------------------------------------------------
QString InputDialog::firstName() const
{
    return m_ptxtFirstName->text();
}

// ----------------------------------------------------------------------
QString InputDialog::lastName() const
{
    return m_ptxtLastName->text();
}

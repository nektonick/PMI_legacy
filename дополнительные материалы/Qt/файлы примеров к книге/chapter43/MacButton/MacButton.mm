// ======================================================================
//  MacButton.mm
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#import "MacButton.h"
#import <Cocoa/Cocoa.h>
#include <QtWidgets>

// ----------------------------------------------------------------------
ButtonContainer::ButtonContainer(QWidget* pwgt/*=0*/)
    : QMacCocoaViewContainer(0, pwgt)
{
    NSAutoreleasePool* ppool = [[NSAutoreleasePool alloc] init];

    NSButton* pcmd = [[NSButton alloc] init];

    [pcmd setButtonType:NSSwitchButton];
    [pcmd setTitle:@"Mac Check Button"];
    [pcmd setState:YES];

    setCocoaView(pcmd);

    [pcmd release];
    [ppool release];
}

// ----------------------------------------------------------------------
QSize ButtonContainer::sizeHint() const
{
    return QSize(150, 40);
}

// ----------------------------------------------------------------------
MacButton::MacButton(QWidget* pwgt) : QWidget(pwgt/*=0*/)
{
    ButtonContainer* pcmd = new ButtonContainer(this);

    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->setContentsMargins(0, 0, 0, 0);
    pvbx->addWidget(pcmd);
    setLayout(pvbx);  
}


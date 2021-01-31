// ======================================================================
//  MacButton.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

#import <qmaccocoaviewcontainer_mac.h>

// ======================================================================
class ButtonContainer : public QMacCocoaViewContainer {
Q_OBJECT
public:
    ButtonContainer(QWidget* pwgt = 0);

    QSize sizeHint() const;
};

// ======================================================================
class MacButton : public QWidget {
Q_OBJECT
public:
    MacButton(QWidget* pwgt = 0);
};



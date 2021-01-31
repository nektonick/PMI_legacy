// ======================================================================
//  Viewer.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QTextEdit>

// ======================================================================
class Viewer : public QTextEdit {
Q_OBJECT
public:
    Viewer(QWidget* pwgt = 0);

private slots:
    void slotDirectoryChanged(const QString&);
    void slotFileChanged     (const QString&);
};

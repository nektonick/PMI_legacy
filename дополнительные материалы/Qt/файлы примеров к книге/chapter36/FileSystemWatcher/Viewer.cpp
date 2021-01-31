// ======================================================================
//  Viewer.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include "Viewer.h"

// ----------------------------------------------------------------------
Viewer::Viewer(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("File System Watcher");
}

// ----------------------------------------------------------------------
void Viewer::slotDirectoryChanged(const QString& str)
{
    append("Directory changed:" + str);
}

// ----------------------------------------------------------------------
void Viewer::slotFileChanged(const QString& str)
{
    append("File changed:" + str);
}


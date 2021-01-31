// ======================================================================
//  FileFinder.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>
#include <QDir>

class QLineEdit;
class QTextEdit;

// ======================================================================
class FileFinder : public QWidget {
    Q_OBJECT
private:
    QLineEdit* m_ptxtDir;
    QLineEdit* m_ptxtMask;
    QTextEdit* m_ptxtResult;

public:
    FileFinder(QWidget* pwgt = 0);    

    void start(const QDir& dir);

public slots:
    void slotFind  ();
    void slotBrowse();
};


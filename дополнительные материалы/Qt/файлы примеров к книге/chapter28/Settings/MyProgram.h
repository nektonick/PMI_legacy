// ======================================================================
//  MyProgram.h --
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;
 
// ======================================================================
class MyProgram : public QWidget {
Q_OBJECT

private:
    QSettings  m_settings;
    QComboBox* m_pcbo;
    QCheckBox* m_pchk;
    QTextEdit* m_ptxt;
    QLabel*    m_plbl;
    int        m_nCounter;

public:
    MyProgram(QWidget* pwgt = 0);
    virtual ~MyProgram();

    void writeSettings();
    void readSettings ();

public slots:
    void slotCheckBoxClicked  (   );
    void slotComboBoxActivated(int);
};

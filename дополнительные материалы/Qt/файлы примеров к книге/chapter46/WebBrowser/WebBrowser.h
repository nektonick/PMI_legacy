// ======================================================================
//  WebBrowser.h - 
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>

class QLineEdit;
class QWebEngineView;
class QPushButton;

// =============================================================
class WebBrowser : public QWidget{
Q_OBJECT
private:
    QLineEdit*      m_ptxt;
    QWebEngineView* m_pwv;
    QPushButton*    m_pcmdBack;
    QPushButton*    m_pcmdForward;

public:
    WebBrowser(QWidget* wgt = 0);

private slots:
    void slotGo      (    );
    void slotFinished(bool);
};



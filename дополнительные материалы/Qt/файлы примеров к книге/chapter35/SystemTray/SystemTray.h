// ======================================================================
//  SystemTray.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QLabel>

class QSystemTrayIcon;
class QMenu;

// ======================================================================
class SystemTray : public QLabel {
Q_OBJECT
private:
    QSystemTrayIcon* m_ptrayIcon;
    QMenu*           m_ptrayIconMenu;
    bool             m_bIconSwitcher;

protected:
    virtual void closeEvent(QCloseEvent*);

public:
    SystemTray(QWidget* pwgt = 0);

public slots:
    void slotShowHide   ();
    void slotShowMessage();
    void slotChangeIcon ();
};


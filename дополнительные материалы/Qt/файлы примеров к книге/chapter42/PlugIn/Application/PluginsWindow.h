// ======================================================================
//  PluginsWindow.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QMainWindow>
#include "interfaces.h"

class QLabel;
class QMenu;
// ======================================================================
class PluginsWindow : public QMainWindow {
Q_OBJECT

private:
    QLabel* m_plbl;
    QMenu*  m_pmnuPlugins;

public:
    PluginsWindow(QWidget* pwgt = 0);

    void loadPlugins(             );
    void addToMenu  (QObject* pobj);

protected slots:
    void slotStringOperation();
};


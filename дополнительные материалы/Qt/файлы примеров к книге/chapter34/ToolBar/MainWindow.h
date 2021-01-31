// ======================================================================
//  MainWindow.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

// ======================================================================
class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget* pwgt = 0) : QMainWindow(pwgt) 
    {
        addToolBar(Qt::TopToolBarArea, createToolBar());
        addToolBar(Qt::BottomToolBarArea, createToolBar());
        addToolBar(Qt::LeftToolBarArea, createToolBar());
        addToolBar(Qt::RightToolBarArea, createToolBar());
    }

    QToolBar* createToolBar()
    {
        QToolBar* ptb = new QToolBar("Linker ToolBar");

        ptb->addAction(QPixmap(":/img1.png"), "1", this, SLOT(slotNoImpl()));
        ptb->addAction(QPixmap(":/img2.png"), "2", this, SLOT(slotNoImpl()));
        ptb->addSeparator();
        ptb->addAction(QPixmap(":/img3.png"), "3", this, SLOT(slotNoImpl()));
        ptb->addAction(QPixmap(":/img4.png"), "4", this, SLOT(slotNoImpl()));

        return ptb;
    }

public slots:
    void slotNoImpl()
    {
        QMessageBox::information(0, "Message", "Not implemented");
    }
};

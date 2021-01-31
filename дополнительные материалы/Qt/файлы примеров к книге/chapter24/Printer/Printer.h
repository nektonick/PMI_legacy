// ======================================================================
//  Printer.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QWidget>

class QPrinter;
class QPaintDevice;

// ======================================================================
class Printer : public QWidget {
    Q_OBJECT

private:
    QPrinter* m_pprinter;

protected:
    virtual void paintEvent(QPaintEvent* pe  );
            void draw      (QPaintDevice* ppd);

public:
    Printer(QWidget* pwgt = 0);
    virtual ~Printer();

public slots:
    void slotPrint();
};

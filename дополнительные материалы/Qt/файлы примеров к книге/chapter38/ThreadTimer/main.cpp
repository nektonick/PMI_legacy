// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "MyWorker.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLCDNumber   lcd;
    QThread      thread;
    MyWorker     worker;

    QObject::connect(&worker, SIGNAL(valueChanged(int)), 
                     &lcd,    SLOT(display(int))
                    );

    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(10);
    lcd.resize(220, 90);
    lcd.show();

    worker.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()),
                     &worker, SLOT(slotDoWork())
                    );

    QObject::connect(&worker, SIGNAL(finished()),
                     &app, SLOT(quit())
                    );

    thread.start();
 
    int nResult = app.exec();

    thread.quit();
    thread.wait();

    return nResult;
}


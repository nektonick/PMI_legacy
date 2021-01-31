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

// ======================================================================
class MyThread : public QThread {
Q_OBJECT

public:
    void run()
    {
        for (int i = 0; i <= 100; ++i) {
            usleep(100000);       
            emit progress(i);
        }
    }

signals:
    void progress(int);
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QProgressBar prb;
    MyThread     thread;

    QObject::connect(&thread, SIGNAL(progress(int)), 
                     &prb,    SLOT(setValue(int))
                    );

    prb.show();

    thread.start();
 
    return app.exec();
}

#include "main.moc"

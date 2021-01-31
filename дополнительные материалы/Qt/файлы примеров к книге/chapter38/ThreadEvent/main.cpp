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
class ProgressEvent : public QEvent {
private:
    int m_nValue;

public:
    enum {ProgressType = User + 1};

    ProgressEvent() : QEvent((Type)ProgressType)
    {
    }

    void setValue(int n) 
    {
        m_nValue = n;
    }
 
    int value() const
    {
        return m_nValue;
    }
};

// ======================================================================
class MyThread : public QThread {
private:
    QObject* m_pobjReceiver;

public:
    MyThread(QObject* pobjReceiver) : m_pobjReceiver(pobjReceiver)
    {
    }

    void run()
    {
        for (int i = 0; i <= 100; ++i) {
            usleep(100000);       

            ProgressEvent* pe = new ProgressEvent;
            pe->setValue(i);
            QApplication::postEvent(m_pobjReceiver, pe);
        }
    }
};

// ======================================================================
class MyProgressBar : public QProgressBar {
public:
    MyProgressBar(QWidget* pwgt = 0) : QProgressBar(pwgt)
    {
    }

    void customEvent(QEvent* pe)
    {
        if ((int)pe->type() == ProgressEvent::ProgressType) {
            setValue(((ProgressEvent*)(pe))->value());
        }
        QWidget::customEvent(pe);
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication  app(argc, argv);
    MyProgressBar prb;
    MyThread      thread(&prb);

    prb.show();

    thread.start();
 
    return app.exec();
}

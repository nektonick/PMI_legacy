// ======================================================================
//  Turtle.h
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
class Turtle : public QWidget {
Q_OBJECT
private:
    QPixmap  m_pix;
    QPainter m_painter;

public:
    Turtle(QWidget* pwgt = 0) : QWidget(pwgt)
                              , m_pix(400, 400)
                              , m_painter(&m_pix)
    {
        setFixedSize(m_pix.size());
        init();
    }

protected:
    void init() 
    {
        m_pix.fill(Qt::yellow);
        m_painter.translate(rect().center());
        m_painter.rotate(-90);
    }

    virtual void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);
        painter.drawPixmap(rect(), m_pix);
    }

public slots:
    void forward(int n)
    {
        m_painter.drawLine(0, 0, n, 0);
        m_painter.translate(n, 0);
        repaint();
    }

    void back(int n)
    {
        m_painter.drawLine(0, 0, -n, 0);
        m_painter.translate(-n, 0);
        repaint();
    }

    void left(int nAngle)
    {
        m_painter.rotate(-nAngle);
    }

    void right(int nAngle)
    {
        m_painter.rotate(nAngle);
    }

    void reset()
    {
        m_painter.resetTransform(); 
        init();
        repaint();
    }
};



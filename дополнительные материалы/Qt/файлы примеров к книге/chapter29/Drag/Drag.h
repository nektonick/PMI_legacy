// ======================================================================
//  Drag.h
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
class Drag : public QLabel {
Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag()
    {
        QMimeData* pMimeData = new QMimeData;
        pMimeData->setText(text());

        QDrag* pDrag = new QDrag(this);
        pDrag->setMimeData(pMimeData);
        pDrag->setPixmap(QPixmap(":/img1.png"));
        pDrag->exec(Qt::MoveAction);
    }

protected:
    virtual void mousePressEvent(QMouseEvent* pe)
    {
        if (pe->button() == Qt::LeftButton) {
            m_ptDragPos = pe->pos();
        }
        QWidget::mousePressEvent(pe);
    }

    virtual void mouseMoveEvent (QMouseEvent* pe)
    {
        if (pe->buttons() & Qt::LeftButton) {
            int distance = (pe->pos() - m_ptDragPos).manhattanLength();
            if (distance > QApplication::startDragDistance()) {
                startDrag();
            }
        }
        QWidget::mouseMoveEvent(pe);
    }

public:
    Drag(QWidget* pwgt = 0) : QLabel("This is a draggable text", pwgt)
    {
    }
};

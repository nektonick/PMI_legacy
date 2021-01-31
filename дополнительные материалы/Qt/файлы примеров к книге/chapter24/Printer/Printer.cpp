// ======================================================================
//  Printer.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include <QtPrintSupport>
#include "Printer.h"

// ----------------------------------------------------------------------
Printer::Printer(QWidget* pwgt/*=0*/) : QWidget(pwgt) 
{
    m_pprinter = new QPrinter;
}

// ----------------------------------------------------------------------
/*virtual*/Printer::~Printer()
{
    delete m_pprinter;
}

// ----------------------------------------------------------------------
/*virtual*/ void Printer::paintEvent(QPaintEvent*) 
{
    draw(this);
}

// ----------------------------------------------------------------------
void Printer::slotPrint()
{
    QPrintDialog dlg(m_pprinter, this);

    dlg.setMinMax(1, 1);
    if (dlg.exec() == QDialog::Accepted) {
        draw(m_pprinter);
    }
}

// ----------------------------------------------------------------------
void Printer::draw(QPaintDevice* ppd)
{
    QPainter painter(ppd);
    QRect    r(painter.viewport());

    painter.setBrush(Qt::white);
    painter.drawRect(r);
    painter.drawLine(0, 0, r.width(), r.height());
    painter.drawLine(r.width(), 0, 0, r.height());

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::red, 3, Qt::DashLine));
    painter.drawEllipse(r);

    painter.setPen(Qt::blue);
    painter.setFont(QFont("Times", 20, QFont::Normal));
    painter.drawText(r, Qt::AlignCenter, "Printer Test");
}

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

// ----------------------------------------------------------------------
QLabel* lbl(const QPainter::CompositionMode& mode)
{
    QLabel* plbl = new QLabel;
    plbl->setFixedSize(100, 100);

    QRect    rect(plbl->contentsRect());
    QPainter painter;

    QImage sourceImage(rect.size(), QImage::Format_ARGB32_Premultiplied);
    sourceImage.fill(QColor(0, 0, 0, 0));
    painter.begin(&sourceImage);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(QColor(0, 255, 0)));
    painter.drawPolygon(QPolygon() << rect.bottomLeft()
                                   << QPoint(rect.center().x(), 0)
                                   << rect.bottomRight()
                       );
    painter.end();

    QImage resultImage(rect.size(), QImage::Format_ARGB32_Premultiplied);
    painter.begin(&resultImage);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.setPen(QPen(QColor(0, 255, 0), 4));
    painter.setBrush(QBrush(QColor(255, 0, 0)));
    painter.drawEllipse(rect);
    painter.setCompositionMode(mode);
    painter.drawImage(rect, sourceImage);
    painter.end();
    
    plbl->setPixmap(QPixmap::fromImage(resultImage));
    return plbl;
}


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
   QApplication app(argc, argv);
   QWidget      wgt;

   //Layout Setup
   QGridLayout* pgrd = new QGridLayout;
   pgrd->addWidget(lbl(QPainter::CompositionMode_Source), 0, 0);
   pgrd->addWidget(new QLabel("<CENTER>Source</CENTER>"), 1, 0);
   pgrd->addWidget(lbl(QPainter::CompositionMode_SourceOver), 0, 1);
   pgrd->addWidget(new QLabel("<CENTER>SourceOver</CENTER>"), 1, 1);
   pgrd->addWidget(lbl(QPainter::CompositionMode_SourceIn), 0, 2);
   pgrd->addWidget(new QLabel("<CENTER>SourceIn</CENTER>"), 1, 2);
   pgrd->addWidget(lbl(QPainter::CompositionMode_SourceOut), 0, 3);
   pgrd->addWidget(new QLabel("<CENTER>SourceOut</CENTER>"), 1, 3);
   pgrd->addWidget(lbl(QPainter::CompositionMode_SourceAtop), 0, 4);
   pgrd->addWidget(new QLabel("<CENTER>SourceAtop</CENTER>"), 1, 4);
   pgrd->addWidget(lbl(QPainter::CompositionMode_Clear), 0, 5);
   pgrd->addWidget(new QLabel("<CENTER>Clear</CENTER>"), 1, 5);
   pgrd->addWidget(lbl(QPainter::CompositionMode_Destination), 2, 0);
   pgrd->addWidget(new QLabel("<CENTER>Destination</CENTER>"), 3, 0);
   pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationOver), 2, 1);
   pgrd->addWidget(new QLabel("<CENTER>DestinationOver</CENTER>"), 3, 1);
   pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationIn), 2, 2);
   pgrd->addWidget(new QLabel("<CENTER>DestinationIn</CENTER>"), 3, 2);
   pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationOut), 2, 3);
   pgrd->addWidget(new QLabel("<CENTER>DestinationOut</CENTER>"), 3, 3);
   pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationAtop), 2, 4);
   pgrd->addWidget(new QLabel("<CENTER>DestinationAtop</CENTER>"), 3, 4);
   pgrd->addWidget(lbl(QPainter::CompositionMode_Xor), 2, 5);
   pgrd->addWidget(new QLabel("<CENTER>Xor</CENTER>"), 3, 5);
   wgt.setLayout(pgrd);

   wgt.show();

   return app.exec();
}

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
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget     wgt;
    QLCDNumber* plcd = new QLCDNumber(4);
    QScrollBar* phsb = new QScrollBar(Qt::Horizontal);

    QObject::connect(phsb, SIGNAL(valueChanged(int)), 
                     plcd, SLOT(display(int))
                    );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(plcd);    
    pvbxLayout->addWidget(phsb); 
    wgt.setLayout(pvbxLayout);

    wgt.resize(250, 150);
    wgt.show();

    return app.exec();
}

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
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;
    wgt.setFixedSize(300, 50);
    wgt.show();

    QLabel* plblOff = new QLabel("Off");
    QLabel* plblOn  = new QLabel("On");

    QHBoxLayout* phbx = new QHBoxLayout;
    phbx->addWidget(plblOn);
    phbx->addStretch(1);
    phbx->addWidget(plblOff);
    wgt.setLayout(phbx);

    QPushButton* pcmd = new QPushButton("Push", &wgt);    
    pcmd->setAutoFillBackground(true);
    pcmd->show();
  
    int nButtonWidth = wgt.width() / 2;

    QStateMachine* psm = new QStateMachine;

    QState* pStateOff = new QState(psm);
    QRect   rect1(0, 0, nButtonWidth, wgt.height());
    pStateOff->assignProperty(pcmd, "geometry", rect1);
    pStateOff->assignProperty(plblOff, "visible", true);
    pStateOff->assignProperty(plblOn, "visible", false);
    psm->setInitialState(pStateOff);

    QState* pStateOn = new QState(psm);
    QRect   rect2(nButtonWidth, 0, nButtonWidth, wgt.height());
    pStateOn->assignProperty(pcmd, "geometry", rect2);
    pStateOn->assignProperty(plblOff, "visible", false);
    pStateOn->assignProperty(plblOn, "visible", true);

    QSignalTransition* ptrans1 = 
        pStateOff->addTransition(pcmd, SIGNAL(clicked()), pStateOn);

    QSignalTransition* ptrans2 = 
        pStateOn->addTransition(pcmd, SIGNAL(clicked()), pStateOff);

    QPropertyAnimation* panim1 = 
        new QPropertyAnimation(pcmd, "geometry");
    ptrans1->addAnimation(panim1);

    QPropertyAnimation* panim2 = 
        new QPropertyAnimation(pcmd, "geometry");
    ptrans2->addAnimation(panim2);

    psm->start();

    return app.exec();
}

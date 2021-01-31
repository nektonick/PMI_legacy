// ======================================================================
//  MyWidget.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include <QQuickWidget>
#include <QQuickItem>
#include "MyWidget.h"

// ----------------------------------------------------------------------
MyWidget::MyWidget(QWidget* pwgt/*=0*/) : QWidget(pwgt)
{
    QQuickWidget* pv = new QQuickWidget(QUrl("qrc:/main.qml"));
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);

    QQuickItem* pqiRoot = pv->rootObject();
    if(pqiRoot) {
        pqiRoot->setProperty("color", "yellow");

        QObject* pObjText = pqiRoot->findChild<QObject*>("text");
        if (pObjText) {
            pObjText->setProperty("text", "C++");
            pObjText->setProperty("color", "blue");

            QVariant varRet;
            QMetaObject::invokeMethod(pObjText, 
                                      "setFontSize", 
                                      Q_RETURN_ARG(QVariant, varRet), 
                                      Q_ARG(QVariant, 52)
                                     );
            qDebug() << varRet;
        } 
    }     
}



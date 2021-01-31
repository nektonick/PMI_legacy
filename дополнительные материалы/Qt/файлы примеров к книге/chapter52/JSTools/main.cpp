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
#include <QJSEngine>
#include "JSTools.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget*     pwgt = new QWidget;

    QPushButton* pcmdFiles = new QPushButton("Show Files");
    pcmdFiles->setObjectName("cmdFiles");

    QPushButton* pcmdQuit = new QPushButton("Quit");
    pcmdQuit->setObjectName("cmdQuit");

    //Layout Setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdFiles);
    pvbxLayout->addWidget(pcmdQuit);
    pwgt->setLayout(pvbxLayout);

    pwgt->show();

    //Script part
    QJSEngine se;
    QFile     file(":/script.js");
    if (file.open(QFile::ReadOnly)) {
        QJSValue sw = se.newQObject(pwgt);

        se.globalObject().setProperty("wgt", sw);

        QList<QObject*> lst = pwgt->findChildren<QObject*>();
        foreach(QObject* pobj, lst) {
            sw = se.newQObject(pobj);
            se.globalObject().setProperty(pobj->objectName(), sw);
        }

        JSTools* pjt = new JSTools;
        sw = se.newQObject(pjt);
        QString strClassName = pjt->metaObject()->className();
        se.globalObject().setProperty(strClassName, sw);

        QJSValue result = 
            se.evaluate(QLatin1String(file.readAll()));
        if (result.isError()) {
            QMessageBox::critical(0, 
                                  "Evaluating error", 
                                  result.toString(), 
                                  QMessageBox::Yes
                                 );
        }
    }
    else {
        QMessageBox::critical(0, 
                              "File open error", 
                              "Can not open the script file", 
                              QMessageBox::Yes
                             );
    }

    return app.exec();
}

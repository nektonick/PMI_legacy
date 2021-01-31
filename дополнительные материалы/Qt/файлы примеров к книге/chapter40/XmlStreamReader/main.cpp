// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtXml>

// ----------------------------------------------------------------------
int main()
{
    QFile file("addressbook.xml");
    if(file.open(QIODevice::ReadOnly)) {
        QXmlStreamReader sr(&file);
        do {
            sr.readNext();
            qDebug() << sr.tokenString() << sr.name() << sr.text();
        } while(!sr.atEnd());

        if (sr.hasError()) {
            qDebug() << "Error:" << sr.errorString();
        }
        file.close();
    }

    return 0;
}

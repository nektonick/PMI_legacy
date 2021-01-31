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
    QApplication     app(argc, argv);
    QStringList      lst;
    QListWidget      lwg;
    QListWidgetItem* pitem = 0;

    lwg.setIconSize(QSize(48, 48));
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst) {
        pitem = new QListWidgetItem(str, &lwg);    
        pitem->setIcon(QPixmap(":/" + str + ".jpg"));
    }
    lwg.resize(125, 175);
    lwg.show();

    return app.exec();
}

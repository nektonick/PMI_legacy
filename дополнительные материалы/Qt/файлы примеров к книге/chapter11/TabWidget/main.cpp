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
    QTabWidget   tab;
    QStringList  lst;

    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst) {
        tab.addTab(new QLabel(str, &tab), QPixmap(":/" + str + ".jpg"), str);
    }
                                                                
    tab.resize(420, 100);
    tab.show();

    return app.exec();
}

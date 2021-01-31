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
    QComboBox    cbo;
    QStringList  lst;

    lst << "John" << "Paul" << "George" << "Ringo";
    cbo.addItems(lst);
    cbo.setEditable(true);
    cbo.show();

    return app.exec();
}

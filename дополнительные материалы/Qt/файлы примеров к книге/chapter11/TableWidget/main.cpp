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
    const int n = 3;

    QApplication      app(argc, argv);
    QTableWidget      tbl(n, n);
    QTableWidgetItem* ptwi = 0;
    QStringList       lst;

    lst << "First" << "Second" << "Third";
    tbl.setHorizontalHeaderLabels(lst);
    tbl.setVerticalHeaderLabels(lst);

    for (int i  = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
            tbl.setItem(i, j, ptwi);
        }
    }
    tbl.resize(370, 135);
    tbl.show();

    return app.exec();
}

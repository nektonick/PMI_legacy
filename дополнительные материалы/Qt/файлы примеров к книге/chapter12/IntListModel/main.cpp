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
#include "IntListModel.h"

// ----------------------------------------------------------------------
int main( int argc, char** argv ) {
    QApplication app( argc, argv );
    IntListModel model(QList<int>() << 123 << 2341 << 32 << 5342 << 723);

    QListView list;
    list.setModel(&model);
    list.show();

    QTableView table;
    table.setModel(&model);
    table.show();

    return app.exec();
}

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
    QFileSystemModel model;
    QTreeView        treeView;

    model.setRootPath(QDir::rootPath());
    treeView.setModel(&model);
    treeView.show();

    return app.exec();
}

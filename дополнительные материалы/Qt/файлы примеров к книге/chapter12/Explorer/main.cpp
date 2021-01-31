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
    QSplitter        spl(Qt::Horizontal);
    QFileSystemModel model;

    model.setRootPath(QDir::rootPath());

    QTreeView* pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    QTableView* pTableView = new QTableView;
    pTableView->setModel(&model);

    QObject::connect(pTreeView,  SIGNAL(clicked(const QModelIndex&)), 
                     pTableView, SLOT(setRootIndex(const QModelIndex&))
                    );
    QObject::connect(pTableView, SIGNAL(activated(const QModelIndex&)), 
                     pTreeView, SLOT(setCurrentIndex(const QModelIndex&))
                    );
    QObject::connect(pTableView, SIGNAL(activated(const QModelIndex&)), 
                     pTableView,  SLOT(setRootIndex(const QModelIndex&))
                    );

    spl.addWidget(pTreeView);
    spl.addWidget(pTableView);
    spl.show();

    return app.exec();
}

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
    QWidget      wgt;

    QStringListModel model;
    model.setStringList(QStringList() << "Xandria"
                                      << "Epica" 
                                      << "Therion" 
                                      << "Evanescence"
                                      << "Nightwish"
                       );

    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel(&model);
    proxyModel.setFilterWildcard("E*");

    QListView* pListView1 = new QListView;
    pListView1->setModel(&model);

    QListView* pListView2 = new QListView;
    pListView2->setModel(&proxyModel);

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;    
    phbxLayout->addWidget(pListView1);
    phbxLayout->addWidget(pListView2);
    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}

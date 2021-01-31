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
    QListWidget      lwg;
    QListWidgetItem* pitem = 0;
    QStringList      lst;

    lwg.setIconSize(QSize(48, 48));
    lwg.setSelectionMode(QAbstractItemView::MultiSelection);
    lwg.setViewMode(QListView::IconMode);
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst) {
        pitem = new QListWidgetItem(str, &lwg);    
        pitem->setIcon(QPixmap(":/" + str + ".jpg"));
        pitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | 
                        Qt::ItemIsEditable | Qt::ItemIsDragEnabled);

    }
    lwg.resize(150, 150);
    lwg.show();

    return app.exec();
}

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
#include <QtSql>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("addressbook");

    db.setUserName("elton"); 
    db.setHostName("epica"); 
    db.setPassword("password"); 
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        return false;
    }
    return true;
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    if (!createConnection()) {
        return -1;
    }

    QTableView               view;
    QSqlRelationalTableModel model;

    model.setTable("addressbook");
    model.setRelation(0, QSqlRelation("status", "number", "married"));
    model.select();
    
    view.setModel(&model);
    view.resize(450, 100);
    view.show();
    
    return app.exec();
}



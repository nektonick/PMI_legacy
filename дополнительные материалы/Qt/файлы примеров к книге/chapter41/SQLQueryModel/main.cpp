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

    QTableView     view;
    QSqlQueryModel model;
    model.setQuery("SELECT phone, email "
                   "FROM addressbook "
                   "WHERE name = 'Piggy';"
                  );

    if (model.lastError().isValid()) {
        qDebug() << model.lastError();
    }
      
    view.setModel(&model);
    view.show();
    
    return app.exec();
}



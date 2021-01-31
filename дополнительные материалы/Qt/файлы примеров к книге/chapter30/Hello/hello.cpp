// ======================================================================
//  hello.cpp --
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load(":/main_ru.qm");
    app.installTranslator(&translator);
 
    QLabel lbl(QObject::tr("Hello"));

    lbl.show();
    return app.exec();
}

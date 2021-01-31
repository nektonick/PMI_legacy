// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtCore>

// ----------------------------------------------------------------------
int main(int, char**)
{
    qDebug() << "Build date:" 
             << QLibraryInfo::buildDate().toString("yyyy-MM-dd");
    qDebug() << "License Products:" 
             << QLibraryInfo::licensedProducts();
    qDebug() << "Licensee:" 
             << QLibraryInfo::licensee();
    qDebug() << "Is Debug Build:" 
             << QLibraryInfo::isDebugBuild();

    qDebug() << "Locations";
    qDebug() << "  Headers:" 
             << QLibraryInfo::location(QLibraryInfo::HeadersPath);
    qDebug() << "  Libraries:" 
             << QLibraryInfo::location(QLibraryInfo::LibrariesPath);
    qDebug() << "  Binaries:" 
             << QLibraryInfo::location(QLibraryInfo::BinariesPath);
    qDebug() << "  Prefix" 
             << QLibraryInfo::location(QLibraryInfo::PrefixPath);
    qDebug() << "  Documentation: " 
             << QLibraryInfo::location(QLibraryInfo::DocumentationPath);
    qDebug() << "  Plugins:" 
             << QLibraryInfo::location(QLibraryInfo::PluginsPath);
    qDebug() << "  Data:" 
             << QLibraryInfo::location(QLibraryInfo::DataPath);
    qDebug() << "  Settings:" 
             << QLibraryInfo::location(QLibraryInfo::SettingsPath);
    qDebug() << "  Examples:" 
             << QLibraryInfo::location(QLibraryInfo::ExamplesPath);
}

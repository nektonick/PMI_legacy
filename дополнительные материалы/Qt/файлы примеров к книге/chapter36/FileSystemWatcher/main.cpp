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
#include "Viewer.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication       app(argc, argv);
    QFileSystemWatcher watcher;
    Viewer             viewer;
 
    QStringList args = app.arguments();
    args.removeFirst();

    watcher.addPaths(args);

    viewer.append("Watching files:" + watcher.files().join(";"));
    viewer.append("Watching dirs:" + watcher.directories().join(";"));
    viewer.show();

    QObject::connect(&watcher, SIGNAL(directoryChanged(const QString&)), 
                     &viewer, SLOT(slotDirectoryChanged(const QString&))
                    );
    QObject::connect(&watcher, SIGNAL(fileChanged(const QString&)), 
                     &viewer, SLOT(slotFileChanged(const QString&))
                    );

    return app.exec();
}

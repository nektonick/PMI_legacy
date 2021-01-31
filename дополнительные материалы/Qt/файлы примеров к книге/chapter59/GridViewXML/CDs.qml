// ======================================================================
//  CDs.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.8
import QtQuick.XmlListModel 2.0

XmlListModel {
    source: "qrc:/CDs.xml"
    query:  "/CDs/CD"
    XmlRole {name: "artist"; query: "artist/string()"}
    XmlRole {name: "album"; query: "album/string()"}
    XmlRole {name: "year"; query: "year/string()"}
    XmlRole {name: "cover"; query: "cover/string()"}
}

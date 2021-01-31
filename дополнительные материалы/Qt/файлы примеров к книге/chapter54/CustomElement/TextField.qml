// ======================================================================
//  TextField.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.8

Rectangle {
    property alias text: txt.text
    property string name: "TextField"

    width: txt.width
    height: txt.height

    Text {
        id: txt
        x: 0
        y: 0
    }
}

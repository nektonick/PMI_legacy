// ======================================================================
//  main.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.8

Rectangle {
    width: 360
    height: 360
    Rectangle {
         color: "lightgreen"
         anchors.fill: text
    }

    Text {
        id: text
        text: "Text"
        anchors.fill: parent
    }
}

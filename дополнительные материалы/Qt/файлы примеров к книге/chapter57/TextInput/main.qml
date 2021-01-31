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
    width: 200
    height: 100
    TextInput {
        anchors.centerIn: parent
        color:  "red"
        text: "Text"
        font.pixelSize: 32
        focus: true
    }
}

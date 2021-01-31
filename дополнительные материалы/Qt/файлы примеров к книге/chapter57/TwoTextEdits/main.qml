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

Item {
    width: 200
    height: 80
    TextEdit {
        id: textedit1
        anchors.left: parent.left
        anchors.right: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        text: "TextEdit1\nTextEdit1\nTextEdit1"
        font.pixelSize: 20
        color: focus ? "red" : "black"
        focus: true
    }

    TextEdit {
        id: textedit2
        anchors.left: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        text: "TextEdit2\nTextEdit2\nTextEdit2"
        font.pixelSize: 20
        color: focus ? "red" : "black"
    }
}

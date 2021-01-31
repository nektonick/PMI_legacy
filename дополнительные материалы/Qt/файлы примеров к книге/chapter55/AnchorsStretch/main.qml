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
    width: 360
    height: 60

    Rectangle {
        id: redrect
        color: "red"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width:  60
    }

    Rectangle {
        color:  "yellow"
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: redrect.right
        anchors.right: greenrect.left
    }

    Rectangle {
        id: greenrect
        color:  "green"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width:  100
    }
}

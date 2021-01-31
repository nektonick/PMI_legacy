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
    height: 200
    color: "lightgreen"
    Text {
        text: "<h1>Hover Me!</h1>"
        anchors.centerIn: parent
    }
    MouseArea {
       id: mousearea
       anchors.fill: parent
       hoverEnabled: true
       onEntered: parent.color = "red"
       onExited: parent.color = "lightgreen"
    }
}

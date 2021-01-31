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
    width: 300
    height: 150

    signal mousePositionChanged(int x, int y)

    onMousePositionChanged:
        txt.text = "<h1>X:" + x + "; Y:" + y + "</h1>"

    Text {
        id: txt
        text: "<h1>Move the Mouse</h1>"
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onMouseXChanged: parent.mousePositionChanged(mouseX, mouseY)
        onMouseYChanged: parent.mousePositionChanged(mouseX, mouseY)
    }
}

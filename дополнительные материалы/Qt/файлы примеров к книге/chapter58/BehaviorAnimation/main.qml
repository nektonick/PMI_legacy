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
    id: rect
    width: 360
    height: 360

    Image {
        id: img
        source: "qrc:/happyos.png"
        x: 10
        y: 10
        smooth: true
        Text {
            anchors.horizontalCenter: img.horizontalCenter
            anchors.top: img.bottom
            text: "Move the mouse!"
        }

        Behavior on x {
            NumberAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
        Behavior on y {
            NumberAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
    }
    MouseArea {
        anchors.fill: rect
        hoverEnabled: true
        onMouseXChanged: img.x = mouseX
        onMouseYChanged: img.y = mouseY
    }
}


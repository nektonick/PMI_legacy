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
    color: "lightgreen"
    width: 300
    height:  300
    Image {
        id: img
        x: 0
        y: 0
        source: "qrc:/happyos.png"
    }
    PropertyAnimation {
        target: img
        properties: "x,y"
        from: 0
        to: 300 - img.height
        duration: 1500
        running: true
        easing.type: Easing.OutExpo
        loops: Animation.Infinite
    }
}

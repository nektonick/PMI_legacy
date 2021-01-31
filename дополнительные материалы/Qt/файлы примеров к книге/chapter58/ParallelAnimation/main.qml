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
    width: 400
    height: 400
    Image {
        id: img
        source: "qrc:/happyos.png"
        smooth: true
        anchors.centerIn: parent
    }

    ParallelAnimation {
        NumberAnimation {
            target: img
            properties: "scale"
            from: 0.1;
            to: 3.0;
            duration: 2000
            easing.type: Easing.InOutCubic
        }
        NumberAnimation {
            target: img
            properties: "opacity"
            from: 1.0
            to: 0;
            duration: 2000
        }
        running: true
        loops: Animation.Infinite
    }
}

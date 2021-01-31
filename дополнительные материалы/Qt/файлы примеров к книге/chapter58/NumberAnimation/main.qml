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
    height: 100
    color: "lightgreen"

    Rectangle {
        x: 0
        y: 0
        height: 100
        color: "red"
        NumberAnimation on width {
            from: 300
            to: 0
            duration: 2000
            easing.type: Easing.InOutCubic
        }
    }
}


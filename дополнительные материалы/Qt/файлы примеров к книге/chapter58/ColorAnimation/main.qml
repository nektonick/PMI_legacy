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
    ColorAnimation on color {
        from: Qt.rgba(1, 0.5, 0, 1)
        to: Qt.rgba(0.5, 0, 1, 1)
        duration: 1500
        running: true
        loops: Animation.Infinite
    }
}

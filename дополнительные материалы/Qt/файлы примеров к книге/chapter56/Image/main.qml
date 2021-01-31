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
    color: "aqua"
    width: img.width
    height: img.height

    Image {
        id: img
        x: 0
        y: 0
        smooth: true
        source: "qrc:/balalaika.png"
        scale: 0.75
        rotation: -30.0
    }
}


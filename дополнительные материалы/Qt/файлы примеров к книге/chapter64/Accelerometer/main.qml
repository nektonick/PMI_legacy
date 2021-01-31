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
import QtSensors 5.1

Rectangle {
    id: mainRect
    width: 320
    height: 480
    color:  "black"

    Rectangle {
        id: rect
        color:  "white"
        x: parent.width / 2
        y: parent.height / 2
        width: parent.width / 6
        height: width
        radius: width / 2

        Accelerometer {
            dataRate: 1000
            skipDuplicates: true
            axesOrientationMode: Accelerometer.FixedOrientation
            active: Qt.application.state
            onReadingChanged: {
                rect.x += reading.x
                rect.y += reading.y
                var maxX = mainRect.width - rect.width
                var maxY = mainRect.height - rect.height
                rect.x = rect.x > maxX ? maxX : rect.x < 0 ? 0 : rect.x
                rect.y = rect.y > maxY ? maxY : rect.y < 0 ? 0 : rect.y
            }
        }
    }
}

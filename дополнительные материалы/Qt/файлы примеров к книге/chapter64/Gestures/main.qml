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
    id: rectMain
    width: 320
    height: 480
    color:  "black"

    Rectangle {
        id: rect
        color:  "white"
        anchors.centerIn: rectMain
        width: Math.min(rectMain.width, rectMain.height) / 2
        height: width

        PinchArea {
            anchors.fill: rect
            pinch.minimumRotation: -360
            pinch.maximumRotation: 360
            pinch.minimumScale: 0.5
            pinch.maximumScale: 2.0

            onPinchStarted: print("PinchStarted")
            onPinchUpdated: {
                rect.rotation = -pinch.angle
                var nW        = rect.width * pinch.scale
                var nMax      = Math.min(rectMain.width, rectMain.height)
                var nMin      = nMax / 2
                rect.width    = nW > nMax ? nMax : nW < nMin ? nMin : nW
                rect.height   = rect.width
            }
            onPinchFinished: print("PinchFinished")
        }
    }
}


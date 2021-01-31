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
import QtQuick.Controls 1.2

ApplicationWindow {
    title: "Image Brightness"
    width: controls.width
    height: controls.height
    visible: true

    Column {
        id: controls
        Image {
            id: img
            source: "image://brightness/Alina.jpg;" + sld.brightnessValue
        }
        Slider {
            id: sld
            width: img.width
            value: 0.75
            stepSize: 0.01
            property int brightnessValue: (value * 255 - 127)
        }
        Text {
            width: img.width
            text: "<h1>Brightness:" + sld.brightnessValue + "</h1>"
        }
    }
}

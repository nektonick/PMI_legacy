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
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Column {
    FastBlur {
        id: blur
        Image {
            id: sourceImage
            visible: false
            source: "qrc:/balalaika.png"
        }

        width: sourceImage.width; 
        height: sourceImage.height
        source: sourceImage
    }
    Slider {
        id: sld
        width: sourceImage.width
        value: 0
        from: 0
        to: 64
        stepSize: 1
        onValueChanged: {  
            blur.radius = value
        }
    }
}

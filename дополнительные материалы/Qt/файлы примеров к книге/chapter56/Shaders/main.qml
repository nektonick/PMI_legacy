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
    width: sourceImage.width
    height: sourceImage.height
    color: "Black"
    ShaderEffect {
        Image {
            id: sourceImage
            width: sourceWidth 
            height: sourceHeight
            visible: false
            source: "qrc:/balalaika.png"
        }

        width: sourceImage.width 
        height: sourceImage.height

        property variant source: sourceImage
        fragmentShader: "
          uniform sampler2D source;
          uniform lowp float qt_Opacity;
          varying highp vec2 qt_TexCoord0;
          void main() {
              gl_FragColor = 
                abs(texture2D(source, qt_TexCoord0) * qt_Opacity - 1.0);
          }"
    }
}

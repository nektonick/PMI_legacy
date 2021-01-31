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
import QtQuick.Particles 2.0

Rectangle {
    width: 360
    height: 360
    color: "MidnightBlue"

    ParticleSystem {
        anchors.fill: parent

        ImageParticle {
            source: "qrc:/snowflake.png"
        }

        Emitter {
            width: parent.width
            height: parent.height
            anchors.bottom: parent.buttom
            lifeSpan: 10000
            sizeVariation: 16
            emitRate: 20
            velocity: 
                AngleDirection {
                    angle: 90
                    angleVariation: 10
                    magnitude: 100
                }
        }
        // wind
        /* 
        Gravity {
            y: parent.height / 2
            width: parent.width
            height: parent.height
            angle: 0
            acceleration: 250
        } 
        */
    }
}
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

Item {
    width: 320
    height: 480

    Text {
        id: txt
        anchors.centerIn: parent

        AmbientLightSensor {
            id: accel
            dataRate: 1000

            skipDuplicates: true
            active: Qt.application.state
            onReadingChanged: {                  
                var lvl = reading.lightLevel
                switch (lvl) {
                case AmbientLightReading.Dark: 
                    txt.text = "Dark" 
                    break
                case AmbientLightReading.Twilight: 
                    txt.text = "Twilight"
                    break
                case AmbientLightReading.Light: 
                    txt.text = "Light"
                    break
                case AmbientLightReading.Bright: 
                    txt.text = "Bright"
                    break
                case AmbientLightReading.Sunny: 
                    txt.text = "Sunny"
                    break
                default: txt.text = "Unknown" 
                }
            }
        }
    }
}

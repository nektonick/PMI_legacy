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
import QtPositioning 5.2

Item {
    width: 320
    height: 480

    Text {
        id: txt
        anchors.centerIn: parent

        PositionSource {
            updateInterval: 1000
            active: Qt.application.state
            onPositionChanged: {
                txt.text = 
                     "Latitude:" + position.coordinate.latitude
                     + "<br>Longitude:" + position.coordinate.longitude
            }
        }
    }
}

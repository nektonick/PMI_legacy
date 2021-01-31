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
import QtQuick.Window 2.2

Item {
    width: 320
    height: 480
    Text {id:txt; anchors.centerIn: parent}
    property int orientation: Screen.primaryOrientation

    onOrientationChanged: {
        if (orientation === Qt.LandscapeOrientation
               || orientation === Qt.InvertedLandscapeOrientation) {
            txt.text = "Landscape Orientation"
        }
        else if (orientation === Qt.PortraitOrientation
              || orientation === Qt.InvertedPortraitOrientation) {
            txt.text = "Portrait Orientation"
        }
    }
}

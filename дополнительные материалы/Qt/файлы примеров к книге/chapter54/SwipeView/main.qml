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

Rectangle {
    width: 340
    height: 480
    SwipeView {
        id: sview
        currentIndex: 1
        width: parent.width
        height: parent.height - 20
        Repeater {
            id: repeater
            model: ["red", "green", "blue", "yellow", "black"]
            Label {
                x: 0
                y: 0
                color: "white"
                background: Rectangle{color: modelData}
                width: sview.width
                height: sview.height
                text: index
                style: Text.Sunken
                font.pixelSize: 256
                font.family: "Courier" 
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            } 
        }
    }
    PageIndicator {
      id: indicator
      count: sview.count
      currentIndex: sview.currentIndex

      x: parent.width / 2 - width / 2 
      y: sview.height
   } 
}

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

Item {
    width: 200
    height: 200
    Rectangle {
       width: parent.width
       height: parent.height
       onWidthChanged: {
           console.log("width changed:" + width)
       }
       onHeightChanged: {
           console.log("height changed:" + height)
       }
    }
}


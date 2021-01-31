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
import QtQuick.Window 2.2
import com.myinc.Ellipse 1.0

Window {
    title: "PaintElement"
    visible: true
    width: 200
    height: 100

    Ellipse {
        anchors.fill: parent
        color: "blue"
    }    
}

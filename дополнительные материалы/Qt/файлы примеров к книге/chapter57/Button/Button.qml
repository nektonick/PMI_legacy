// ======================================================================
//  Button.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.8

BorderImage {
    property alias text: txt.text
    signal clicked;

    source: "qrc:/mybutton.png"
    width: txt.width + 15  
    height: txt.height + 15 
    border {left: 15; top: 12; right: 15; bottom: 12}

    Text {
        id: txt
        color:  "white"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked();
        onPressed: parent.source = "qrc:/mybuttonpressed.png"
        onReleased: parent.source = "qrc:/mybutton.png"
    }
}



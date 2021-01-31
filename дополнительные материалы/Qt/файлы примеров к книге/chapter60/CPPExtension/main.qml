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
    color: myColor
    width: 200
    height: 200
    Text {
        anchors.centerIn: parent
        text: myText
    }
    ListView {
        anchors.fill: parent
        model: myModel
        delegate: Text {text: model.display} 
    }  
    MouseArea {
        anchors.fill: parent
        onPressed: {
            myWidget.setWindowTitle("Hello from QML");
            myWidget.slotDisplayDialog();
        }
    } 
}

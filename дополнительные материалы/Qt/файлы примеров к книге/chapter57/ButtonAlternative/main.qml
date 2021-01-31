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
    width: 150
    height: 100
    Button {
        anchors.centerIn: parent
        text: "Please, Click me!"
        onClickedChanged: {
            text = "Clicked!"
        }
    }
}

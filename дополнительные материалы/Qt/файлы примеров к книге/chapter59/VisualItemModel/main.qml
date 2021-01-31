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
    width: 250;
    height: 250;
    color: "DarkSlateGray"

    Flickable {
        id: view
        width: 250
        height: 500
        contentWidth: 250
        contentHeight: column.height
        anchors.fill: parent

        Column {
            id: column
            anchors.fill: view
            spacing: 5
            Repeater {
                model: CDs{}
            }         
        } 
    }
}
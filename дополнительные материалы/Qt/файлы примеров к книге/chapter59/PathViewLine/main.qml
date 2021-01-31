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
    color: "gray"
    width: 450
    height: 170
    Component {
        id: delegate
        Item {
            width: item.width
            height: item.height
            Column {
                id: item
                Image {
                    width: 90
                    height: 90
                    source: cover
                    smooth: true
                }
                Text {color: "white"; text: artist; font.pointSize: 12}
                Text {color: "lightblue"; text: album; font.pointSize: 10}
                Text {color: "yellow"; text: year; font.pointSize: 8}
            }
        }
    }
    Path {
        id: itemsPath
        startX: 0
        startY: 80
        PathLine {x: 500; y: 80}
    }
    PathView {
        id: itemsView
        anchors.fill: parent
        model: CDs {}
        delegate: delegate
        path: itemsPath
        pathItemCount: 4
    }
}


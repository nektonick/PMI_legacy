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
    id: mainrect
    color:  "gray"
    width: 380
    height: 420
    Component {
        id: delegate
        Item {
            width: 120
            height: 120
            Column {
               anchors.centerIn: parent
               Image {
                   anchors.horizontalCenter: parent.horizontalCenter
                   width: 64
                   height: 64
                   source: cover
                   smooth: true
               }
               Text {color: "white"; text: artist; font.pointSize: 12}
               Text {color: "lightblue"; text: album; font.pointSize: 10}
               Text {color: "yellow"; text: year; font.pointSize: 8}
           }
        }
    }
    GridView {
        cellHeight: 120
        cellWidth: 120
        focus:  true
        header: Rectangle {
            width: parent.width
            height: 30
            gradient: Gradient {
                GradientStop {position: 0; color: "gray"}
                GradientStop {position: 0.7; color: "black"}
            }
            Text{
                anchors.centerIn: parent;
                color: "gray";
                text: "CDs"
                font.bold: true;
                font.pointSize: 20
            }
        }
        footer: Rectangle {
            width: parent.width
            height: 30
            gradient: Gradient {
                GradientStop {position: 0; color: "gray"}
                GradientStop {position: 0.7; color: "black"}
            }
        }
        highlight: Rectangle {
            width: parent.width
            color: "darkblue"
        }

        anchors.fill: parent
        model: CDs{}
        delegate: delegate
    } 
}

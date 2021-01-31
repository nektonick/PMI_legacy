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
    width: 300
    height: 300
    Rectangle {
        id: rect
        width: 100
        height:  100
        color: "magenta"
        state: "State1"
        Text {
            anchors.centerIn: parent
            text: "Click me!"
        }
        MouseArea {
            anchors.fill: rect
            onClicked:
             rect.state = (rect.state == "State1") ? "State2" : "State1"
        }
        states: [
            State {
                name: "State1"
                PropertyChanges {target: rect; x: 0; y: 0}
            },
            State {
                name: "State2"
                PropertyChanges {target: rect; x: 200; y: 200}
            }
        ]
        transitions: [
            Transition {
                from: "State1"; to: "State2"
                PropertyAnimation {
                    target: rect;
                    properties: "x,y";
                    easing.type: Easing.InCirc
                    duration: 1000
                }
            },
            Transition {
                from: "State2"; to: "State1"
                PropertyAnimation {
                    target: rect
                    properties: "x,y";
                    easing.type: Easing.InBounce
                    duration: 1000
                }
            }
        ]
    }
}

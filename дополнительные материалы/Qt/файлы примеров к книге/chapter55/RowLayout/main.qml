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
import QtQuick.Layouts 1.3

Item {
    width: 320
    height: 240

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10

        spacing: 10
        Rectangle {
            Layout.fillHeight: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "red"
        }
        Rectangle {
            Layout.fillWidth: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "blue"
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "green"
        }
    }
}

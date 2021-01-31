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

Window {
    visible: true
    width: 150
    height: 150
    Column {
        anchors.centerIn: parent
        Button {
            signal infoClicked(string str)
            objectName: "InfoButton"
            text: "Info"
            onClicked: infoClicked("Information")
        }
        Button {
            signal quitClicked()
            objectName: "QuitButton"
            text: "Quit"
            onClicked: quitClicked()
        }
    }
}

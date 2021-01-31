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

ApplicationWindow {
    width: buttons.width
    height: buttons.height
    visible: true
    title: "Buttons"

    Column {
        id: buttons
        CheckBox{text: "Check Box"}
        DelayButton{text: "Delay Button"}
        RadioButton{text: "Radio Button"}
        RoundButton{text: "Round Button"}
        Switch{text: "Switch"}
        ToolButton{text: "Tool Button"}
        Button{text: "Quit"; onClicked: Qt.quit()}
    }
}

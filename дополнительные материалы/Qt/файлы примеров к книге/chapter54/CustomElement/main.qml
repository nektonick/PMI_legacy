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

    TextField {
        x: 10
        y: 20
        color: "yellow"
        text: name + "<br>Text Text Text<br>Text Text Text"
        border.width: 1
    }
}

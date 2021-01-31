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
    width: 200
    height: 100
    Text {
        x: 20;
        y: 20;
        text: "Move this text<br>(use the cursor-keys)"
        horizontalAlignment: Text.AlignHCenter
        Keys.onPressed: {
            if (event.key == Qt.Key_Left) {
                x -= 3;
            }
            else if (event.key == Qt.Key_Right) {
                x += 3;
            }
            else if (event.key == Qt.Key_Down) {
                y += 3;
            }
            else if (event.key == Qt.Key_Up) {
                y -= 3;
            }
            else if (event.key == Qt.Key_Plus) {
                font.pixelSize++;
            }
            else if (event.key == Qt.Key_Minus) {
                font.pixelSize--;
            }
        }
        focus:  true
    }
}

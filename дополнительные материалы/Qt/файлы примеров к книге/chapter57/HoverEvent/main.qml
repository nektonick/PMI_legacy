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
   height: 200
   color: mousearea.containsMouse ? "red" : "lightgreen"

   Text {
      anchors.centerIn: parent
      text: "<h1>Hover Me!</h1>"
   }

   MouseArea {
      id: mousearea
      anchors.fill: parent
      hoverEnabled: true
   }
}

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
import "qrc:/CDs.js" as CDs

Rectangle {
    id: mainrect
    color:  "gray"
    width: 200
    height: 360

    Component {
        id: delegate
        Item {
            width: mainrect.width
            height: 70
            Row {
               anchors.verticalCenter: parent.verticalCenter
               Image {
                   width: 64
                   height: 64
                   source: modelData.cover
                   smooth: true
               }
               Column {
                   Text {color: "white" 
                         text: modelData.artist 
                         font.pointSize: 12
                        }
                   Text {color: "lightblue"
                         text: modelData.album
                         font.pointSize: 10
                        }
                   Text {color: "yellow"
                         text: modelData.year
                         font.pointSize: 8
                        }
               }
           }
        }
    } 

    ListView {
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
        model: CDs.jsonModel
        delegate: delegate  
    }
}

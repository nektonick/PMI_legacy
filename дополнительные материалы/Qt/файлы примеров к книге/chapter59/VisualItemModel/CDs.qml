// ======================================================================
//  CDs.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.8

VisualItemModel {
    Row {
       Image {
           width: 64
           height: 64
           source: "qrc:/covers/TheUnforgiving.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Within Temptation"; font.pointSize: 12}
           Text {color: "lightblue"; text: "The Unforgiving"; font.pointSize: 10}
           Text {color: "yellow"; text: "2011"; font.pointSize: 8}
       }
    }
    Rectangle {
        width: parent.width
        height: 64
        color: "Yellow"
        Text {
            anchors.centerIn: parent
            color: "Red"
            text: "Blank!"
        }
    } 
    Row {
       Image {
           width: 64
           height: 64
           source: "qrc:/covers/Amaranthe.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Amaranthe"; font.pointSize: 12}
           Text {color: "lightblue"; text: "Amaranthe"; font.pointSize: 10}
           Text {color: "yellow"; text: "2011"; font.pointSize: 8}
       }
    }
    Row {
       Image {
           width: 64
           height: 64
           source: "qrc:/covers/WithoutYou.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Dark Princess"; font.pointSize: 12}
           Text {color: "lightblue"; text: "Without You"; font.pointSize: 10}
           Text {color: "yellow"; text: "2005"; font.pointSize: 8}
       }
    }
    Row {
       Image {
           width: 64
           height: 64
           source: "qrc:/covers/Fallen.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Evanescence"; font.pointSize: 12}
           Text {color: "lightblue"; text: "Fallen"; font.pointSize: 10}
           Text {color: "yellow"; text: "2003"; font.pointSize: 8}
       }
    }
    Row {
       Image {
           width: 64
           height: 64
           source:  "qrc:/covers/Rubicon.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Tristania"; font.pointSize: 12}
           Text {color: "lightblue"; text: "Rubicon"; font.pointSize: 10}
           Text {color: "yellow"; text: "2010"; font.pointSize: 8}
       }
    }
    Row {
       Image {
           width: 64
           height: 64
           source:  "qrc:/covers/TheDivineConspirancy.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Epica"; font.pointSize: 12}
           Text {color: "lightblue"; text: "The Divine Conspiracy"; font.pointSize: 10}
           Text {color: "yellow"; text: "2007"; font.pointSize: 8}
       }
    }
    Row {
       Image {
           width: 64
           height: 64
           source:  "qrc:/covers/AprilRain.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Delain"; font.pointSize: 12}
           Text {color: "lightblue"; text: "April Rain"; font.pointSize: 10}
           Text {color: "yellow"; text: "2010"; font.pointSize: 8}
       }
    }
    Row {
       Image {
           width: 64
           height: 64
           source:  "qrc:/covers/NineDestiniesAndADownfall.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Sirenia"; font.pointSize: 12}
           Text {color: "lightblue"; text: "The End of it All"; font.pointSize: 10}
           Text {color: "yellow"; text: "2011"; font.pointSize: 8}
        }
    }
    Row {
       Image {
           width: 64
           height: 64
           source:  "qrc:/covers/DarkPassionPlay.jpg"
           smooth: true
       }
       Column {
           Text {color: "white"; text: "Nightwish"; font.pointSize: 12}
           Text {color: "lightblue"; text: "Dark Passion Play"; font.pointSize: 10}
           Text {color: "yellow"; text: "2007"; font.pointSize: 8}
       }
    }
}

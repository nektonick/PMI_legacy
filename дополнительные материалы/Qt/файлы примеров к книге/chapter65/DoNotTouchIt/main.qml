// ======================================================================
//  main.qml
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

import QtQuick 2.9
import QtQuick.Dialogs 1.2
import QtQuick.Extras 1.4 as QQE
import QtMultimedia 5.9
import QtSensors 5.9

Rectangle {
    id: main
    width: 320
    height: 480
    property int minDim: Math.min(width, height)
    property bool alarm: false

    Image {
        id: infoButton
        anchors.bottom: main.bottom
        width:  main.minDim / 6
        height:  width
        source: "qrc:/InfoButton.png"
        MouseArea {
            anchors.fill: infoButton
            onClicked: aboutDialog.visible = true
        }
    }
    MessageDialog {
        id: aboutDialog
        visible: false
        title: "Do Not Touch It"
        text: "Version 1.0 for " + Qt.platform.os
    }

    Text {
        anchors.top: main.top
        anchors.horizontalCenter: main.horizontalCenter
        font.pixelSize: main.minDim / 15
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        text: main.alarm ? "DO NOT TOUCH IT!"
                          : "Put your device\non a smooth surface"
    }
    QQE.DelayButton {
        id: btn
        width: main.minDim / 1.5
        height: width
        anchors.centerIn: main
        text: checked ? "Deactivate" : "Tap & Hold<br>to Activate"
        onCheckedChanged: main.alarm = false
    }
    Gyroscope {
        active: btn.checked
        alwaysOn: btn.checked
        axesOrientationMode: Gyroscope.FixedOrientation
        skipDuplicates: true
        onReadingChanged: {
            var movement = Math.max(Math.abs(reading.x), 
                                    Math.abs(reading.y), 
                                    Math.abs(reading.z)
                                   )
            if (movement > 10 && btn.checked) {
                main.alarm = true
            }
        }
    }

    Timer {
        id: timer
        interval: 250
        repeat: true
        property bool bBlink: false
        onTriggered:  {
            main.color = bBlink ? "white" : "red"
            bBlink = !bBlink
        }
        onRunningChanged: {
            if (!running) {
                main.color = "white"
            }
        }
    }
    MediaPlayer {
        id: sound
        source: (assetsPath + "alarm.mp3")
        loops: MediaPlayer.Infinite
        volume: 1
    }
    onAlarmChanged: {
        if (alarm) {
            sound.play()
            timer.start()
        }
        else {
            timer.stop()
            sound.stop()
        }
    }
}

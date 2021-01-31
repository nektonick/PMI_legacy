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
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    width: 200
    height: 150
    visible: true
    title: "Dialogs Demo"

    Repeater {
        id: repeater
        model: [colorDialog, fontDialog, fileDialog]
        Button {
            y: index * (parent.height / repeater.count)
            height: parent.height / repeater.count
            width: parent.width
            text: modelData.title
            onClicked: {
                messageDialog.visible = false;
                modelData.visible = true;
            }
        }
    }

    ColorDialog {
        id: colorDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select color"
        color: "blue"
        onAccepted: { 
             messageDialog.informativeText = "Selected color: " + color
             messageDialog.visible = true
        }
    }

    FontDialog {
        id: fontDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select font"
        onAccepted: { 
             messageDialog.informativeText = "Selected font: " + font
             messageDialog.visible = true
        }
    }

    FileDialog {
        id: fileDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select file"
        folder: "file://Users/"
        nameFilters: ["Doc (*.txt *.html)", "All files (*)"]
        onAccepted: { 
             messageDialog.informativeText = "Selected file: " + fileUrls
             messageDialog.visible = true
        }
    }

    MessageDialog {
        id: messageDialog
        visible: false
        modality: Qt.NonModal
        title: "Message"
    }
}

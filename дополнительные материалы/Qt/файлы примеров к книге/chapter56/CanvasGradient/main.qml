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

Canvas {
    id: canv
    width: 320
    height: 320
    onPaint: {
        var ctx = getContext("2d")
        ctx.strokeStyle = "Blue"
        ctx.lineWidth = 15
        var gradient = 
         ctx.createLinearGradient(canv.width, canv.height, 0, 0)
        gradient.addColorStop(0, "Indigo")
        gradient.addColorStop(0.5, "Bisque")
        gradient.addColorStop(1, "ForestGreen")
        ctx.fillStyle = gradient
        ctx.fillRect(0, 0, canv.width, canv.height)
        ctx.strokeRect(0, 0, canv.width, canv.height)
    }
}
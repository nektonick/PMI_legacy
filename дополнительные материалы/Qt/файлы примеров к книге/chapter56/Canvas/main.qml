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
    width: 400
    height: 400

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            function drawFantasy()
            {
                ctx.beginPath()
                ctx.translate(parent.width / 2, parent.height / 2)
                var fAngle = 91 * 3.14156 / 180
                for (var i = 0; i < 300; ++i) {
                    var n = i * 2
                    ctx.moveTo(0, 0)
                    ctx.lineTo(n, 0)
                    ctx.translate(n, 0)

                    ctx.rotate(fAngle)
                }
                ctx.closePath()
            }

            var ctx = getContext("2d");
            ctx.clearRect(0, 0, parent.width, parent.height)

            ctx.save();
            ctx.strokeStyle = "black"
            ctx.lineWidth = 1

            drawFantasy();

            ctx.stroke();
            ctx.restore();
        }
    }
}

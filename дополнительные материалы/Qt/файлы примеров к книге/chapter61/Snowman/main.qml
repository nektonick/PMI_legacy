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
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick.Scene3D 2.0

Rectangle {
    id: scene
    color: "black"

    Scene3D {
        id: scene3d
        anchors.fill: parent
        focus: true
        aspects: ["input", "logic"]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

        Entity {
            Camera {
                id: camera
                fieldOfView: 90
                nearPlane : 0.1
                farPlane : 1000.0
                position: Qt.vector3d( 0.0, 10.0, 40.0 )
            }

            FirstPersonCameraController {
                camera: camera
                linearSpeed: 1000.0
                acceleration: 0.1
                deceleration: 1.0
            }

            Entity {
                PointLight {
                    id: pointL
                    color: "#afafff"
                }
                Transform{
                    id: plightpostransform
                    translation: Qt.vector3d(0.0, 4.0, 15.0)
                }
                components: [plightpostransform, pointL]
            } 

            components: [
                RenderSettings {
                    activeFrameGraph: 
                        ForwardRenderer {
                            camera: camera
                            clearColor: "transparent"
                        }
                },
                InputSettings { }
            ]

            Snowman{}
        }
    }
}

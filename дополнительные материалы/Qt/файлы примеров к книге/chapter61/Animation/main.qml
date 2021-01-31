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
            Camera { //Camera
                id: camera
                nearPlane : 0.1
                farPlane : 1000.0
                position: Qt.vector3d( 0.0, 0.0, 60.0 )
            }
            FirstPersonCameraController {
                camera: camera
                linearSpeed: 1000.0
                acceleration: 0.1
                deceleration: 1.0
            }
            Entity { //Light
                DirectionalLight {
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
            Entity {  //Sphere
                PhongMaterial {
                    id: phongMaterial
                    ambient: Qt.rgba( 0.3, 0.3, 0.3, 1.0 )
                    diffuse: Qt.rgba( 1, 1, 1, 1 )
                }
                SphereMesh {
                    id: sphereMesh
                    radius: 6
                }
                Transform {
                    id: sphereTransform
                    property real myParam: 0
                    matrix: {
                        var mat = Qt.matrix4x4();
                        mat.rotate(myParam, Qt.vector3d(0, 1, 0))
                        mat.translate(Qt.vector3d(24, 0, 0));
                        return mat;
                    } 
                }
                components: [sphereMesh, phongMaterial, sphereTransform]
                NumberAnimation {
                    target: sphereTransform
                    property: "myParam"
                    duration: 10000
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    running: true
                }
            }            

            Entity {  //Pyramid
                GoochMaterial {
                    id: goochMaterial
                    diffuse: Qt.rgba( 1, 1, 1, 1 )
                }
                Mesh {
                    id: pyramidMesh
                    source: "qrc:/pyramid.obj"
                }
                Transform {
                    id: pyramidTransform
                    property real myRotation: 0
                    matrix: {
                        var mat = Qt.matrix4x4();
                        mat.rotate(myRotation, Qt.vector3d(1, 1, 1))
                        mat.scale(Qt.vector3d(10, 10, 10));
                        return mat;
                    } 
                }
                components: [pyramidMesh, goochMaterial, pyramidTransform]
                NumberAnimation {
                    target: pyramidTransform
                    property: "myRotation"
                    duration: 10000
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    running: true
                }
            }            
        }
    }
}

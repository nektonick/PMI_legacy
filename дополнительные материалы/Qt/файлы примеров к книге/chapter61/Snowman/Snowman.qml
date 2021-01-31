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
import Qt3D.Extras 2.0

Entity {
    id: snowman
    PhongMaterial {
        id: snowMaterial
        ambient: Qt.rgba( 0.3, 0.3, 0.3, 1.0 )
        diffuse: Qt.rgba( 1, 1, 1, 1 )
    }

    Entity {
        SphereMesh {
            id: sphereMesh1
            radius: 1
        }
        Transform {
            id: sphereTransform1
            translation: Qt.vector3d(0, 3, 0)
            scale: 5.0
        }
        components: [sphereMesh1, snowMaterial, sphereTransform1]
    }            
    Entity {
        SphereMesh {
            id: sphereMesh2
            radius: 1
        }
        Transform {
            id: sphereTransform2
            translation: Qt.vector3d(0, 10, 0)
            scale: 3.5
        }
        components: [sphereMesh2, snowMaterial, sphereTransform2]
    }
    Entity {
        SphereMesh {
            id: sphereMesh3
            radius: 1
        }
        Transform {
            id: sphereTransform3
            translation: Qt.vector3d(0, 15, 0)
            scale: 2.0
        }
        components: [sphereMesh3, snowMaterial, sphereTransform3]
    }

    PhongMaterial {
        id: eyeMaterial
        diffuse: Qt.rgba( 0.1, 0.1, 1, 1 )
    }
    Entity {
        SphereMesh {
            id: eyeMesh1
            radius: 0.3
        }
        Transform {
            id: eyeTransform1
            translation: Qt.vector3d(1, 15, 1.7)
        }
        components: [eyeMesh1, eyeMaterial, eyeTransform1]
    }
    Entity {
        SphereMesh {
            id: eyeMesh2
            radius: 0.3
        }
        Transform {
            id: eyeTransform2
            translation: Qt.vector3d(-1, 15, 1.7)
        }
        components: [eyeMesh2, eyeMaterial, eyeTransform2]
    }

    PhongMaterial {
        id: cylinderMaterial
        diffuse: Qt.rgba( 1, 1, 1, 1 )
    }
    Entity {
        CylinderMesh {
            id: cylinderMesh1
            radius: 1
            length: 2
        }
        Transform {
            id: cylinderTransform1
            translation: Qt.vector3d(0, 18, 0)
            scale: 1.5
        }
        components: [ cylinderMesh1, cylinderMaterial, cylinderTransform1 ]
    }
    Entity {
        CylinderMesh {
            id: cylinderMesh2
            radius: 6
            length: 0.5
        }
        Transform {
            id: cylinderTransform2
            translation: Qt.vector3d(0, 16.5, 0)
            scale: 0.5
        }
        components: [ cylinderMesh2, cylinderMaterial, cylinderTransform2 ]
    }
    Entity {
        ConeMesh {
            id: coneMesh1
            topRadius: 0
            bottomRadius: 1
            length: 5
            rings: 50
        }
        Transform {               
            id: coneTransform1
            scale: 0.5
            translation: Qt.vector3d(0, 14, 4)
            rotationX: 90
        }
        PhongMaterial {
            id: coneMaterial1
            diffuse: Qt.rgba(1, 0.3, 0.2, 1)
        }
        components: [ coneMesh1, coneMaterial1, coneTransform1 ]
    }
}

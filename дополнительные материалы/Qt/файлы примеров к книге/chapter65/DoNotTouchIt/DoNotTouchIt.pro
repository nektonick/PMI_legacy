TEMPLATE = app
TARGET	= DoNotTouchIt
QT += quick qml sensors multimedia 
SOURCES += main.cpp
RESOURCES += resources.qrc 
APP_FILES.files +=  ../../common/alarm.mp3
ios { 
    QMAKE_INFO_PLIST = _ios/IosInfo.plist
    QMAKE_BUNDLE_DATA += APP_FILES
    QMAKE_ASSET_CATALOGS += $$PWD/_ios/Images.xcassets
}
android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/_android
    OTHER_FILES += _android/AndroidManifest.xml                         
    APP_FILES.path = /assets/Resources
    APP_FILES.depends += FORCE
    INSTALLS += APP_FILES 
}

import QtQuick 2.12
import untitled3 1.0
  import Qt.SafeRenderer 1.1

Rectangle {
    width: Constants.width
    height: Constants.height
    color: "#55aa00"

    Text {
        text: qsTr("Hello untitled3")
        anchors.centerIn: parent
        font.family: Constants.font.family
    }

    SafeText {
        id: safeText
        x: 179
        y: 368
    }

    Image {
        id: image
        x: 31
        y: 51
        width: 472
        height: 329
        fillMode: Image.PreserveAspectFit
        source: "shutterstock_323570969.jpg"
    }
}

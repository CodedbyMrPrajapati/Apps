import QtQuick

Item {
    id: root
    
    implicitWidth: icon.width + (hovered ? labelItem.implicitWidth : 0 ) + 24
    width: implicitWidth

    // height: parent ? parent.height * 0.08 : 40
    implicitHeight: 40


    property string label: ""
    property string iconSource: ""
    property bool selected: false
    signal clicked()
    property int index: -1


    property bool hovered: false

    // Background
    Rectangle {
        id: bg
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        radius: height * 0.3
        color: selected
               ? '#57363840'
               : hovered ? '#38636363'
                         : "transparent"

        Behavior on color { ColorAnimation { duration: 140 } }
    }

    // ICON
    Image {
        id: icon
        source: iconSource
        fillMode: Image.PreserveAspectFit

        width: root.height * 0.55
        height: width

        anchors.verticalCenter: parent.verticalCenter

        // Icon slides left when expanded
        anchors.left: parent.left
        anchors.leftMargin: hovered ? root.height * 0.08 : root.height * 0.25

        Behavior on anchors.leftMargin {
            NumberAnimation { duration: 180; easing.type: Easing.OutQuad }
        }
    }

    // TEXT (revealed only when expanded)
    Text {
        id: labelItem
        text: root.label
        color: selected ? "white"
              : hovered ? "#f0f0f0"
                        : "#c4c5c9"

        opacity: hovered ? 1 : 0

        anchors.verticalCenter: parent.verticalCenter
        anchors.left: icon.right
        anchors.leftMargin: hovered ? root.width*0.05: 0

        font.pixelSize: height * 0.55

        Behavior on opacity { NumberAnimation { duration: 140 } }
        Behavior on color   { ColorAnimation { duration: 140 } }
    }

    MouseArea {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        height: parent.height

        hoverEnabled: true

        onClicked: root.clicked()

        onEntered: root.hovered = true
        onExited:  root.hovered = false
    }

    scale: hovered ? 1.03 : 1.0
    Behavior on scale {
        NumberAnimation { duration: 130; easing.type: Easing.OutQuad }
    }
}

import QtQuick

Item {
    id: popup
    anchors.bottom: parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width * 0.9
    height: 40
    visible: false
    opacity: 0
    y: parent.height - height - 20

    Rectangle {
        anchors.fill: parent
        radius: 8
        color: '#a6ff1b39'   // translucent red
    }

    Text {
        anchors.centerIn: parent
        color: "white"
        text: popup.msg
    }

    property string msg: ""

    function show(m) {
        msg = m
        visible = true
        opacity = 1
        fadeOut.start()
    }

    NumberAnimation on opacity {
        id: fadeOut
        from: 1; to: 0
        duration: 4500
        onFinished: visible = false
    }
}


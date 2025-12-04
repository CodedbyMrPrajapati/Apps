import QtQuick
import QtQuick.FileDialog
Rectangle {
    width: 600
    height: 400
    color: "transparent"
    FileDialog {
        id: jsonDialog
        title: "Select JSON"
        nameFilters: ["JSON Files (*.json)"]
        onAccepted: popup.show("JSON selected")
        onRejected: popup.show("Cancelled")
    }
    FileDialog {
        id: folderDialog
        title: "Select Output Folder"
        selectFolder: true
        onAccepted: popup.show("Folder selected")
        onRejected: popup.show("Cancelled")
    }

    Column {
        anchors.centerIn: parent
        spacing: 18

        Text {
            text: "JSON → Directory"
            font.pixelSize: 28
            color: "#ddd"
        }

        Rectangle {
            width: 260; height: 42; radius: 10
            color: "#2b2d31"
            Text { anchors.centerIn: parent; text: "Select JSON"; color: "#ccc" }
            MouseArea {
                anchors.fill: parent
                onClicked: jsonDialog.open()
            }
        }

        Rectangle {
            width: 260; height: 42; radius: 10
            color: "#2b2d31"
            Text { anchors.centerIn: parent; text: "Select Output Folder"; color: "#ccc" }
            MouseArea {
                anchors.fill: parent
                onClicked: folderDialog.open()
            }
        }

        Rectangle {
            width: 260; height: 42; radius: 10
            color: "#3a3c43"
            Text { anchors.centerIn: parent; text: "Preview"; color: "#fff" }
        }
    }
}

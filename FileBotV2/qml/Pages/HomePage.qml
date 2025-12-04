import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root
    anchors.fill: parent

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 12
        width: parent.width * 0.6

        Text {
            text: "Welcome to FileBot V2"
            color: "#ffffff"
            font.pixelSize: 32
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }

        Text {
            text: "Your personal file automation and organization assistant."
            color: "#aaaaaa"
            font.pixelSize: 18
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Rectangle {
            height: 1
            Layout.fillWidth: true
            color: "#2f2f2f"
            radius: 1
        }

        ColumnLayout {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter

            Text {
                text: "Available Tools"
                color: "#cccccc"
                font.pixelSize: 20
                Layout.alignment: Qt.AlignHCenter
            }

            Repeater {
                model: [
                    "• JSON → Directory Builder",
                    "• File Organizer",
                    "• Folder Cleaner",
                    "• Document Sorter",
                ]

                Text {
                    text: modelData
                    color: "#888888"
                    font.pixelSize: 16
                }
            }
        }

        Rectangle {
            height: 40
            width: 260
            radius: 6
            color: "#5865F2"   // Discord accent color
            Layout.alignment: Qt.AlignHCenter

            Text {
                anchors.centerIn: parent
                text: "Get Started"
                color: "white"
                font.pixelSize: 16
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: console.log("Home: Get Started pressed")
            }
        }
    }
}

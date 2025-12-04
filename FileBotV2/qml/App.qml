import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "Components"

Rectangle {
    width: 1000
    height: 600
    color: Theme.bg

    RowLayout {
        anchors.fill: parent

        Sidebar { }

        StackLayout {
            id: pageStack
            Layout.fillWidth: true
            Layout.fillHeight: true

            HomePage { }
            JsonToDirPage { }
        }
    }
}

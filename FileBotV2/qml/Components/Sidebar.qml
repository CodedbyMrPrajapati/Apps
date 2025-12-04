import QtQuick
import QtQuick.Layouts
import "."

Rectangle {
    id: sidebar
    width: parent.width * 0.10
    color: Qt.rgba(0.12, 0.12, 0.15, 0.35)
    radius: width * 0.15


    signal pageSelected(int index)
    property int currentIndex: 0

    // Smooth expansion
    Behavior on width {
        NumberAnimation { duration: 180; easing.type: Easing.InOutQuad }
    }

    MouseArea {
        id: hoverArea
        anchors.fill: parent
        hoverEnabled: true
        // **Do NOT eat clicks**
        acceptedButtons: Qt.NoButton
        z:99999
    }

    Column {
        anchors.fill: parent
        anchors.margins: sidebar.width * 0.05
        spacing: height * 0.05

        SidebarItem {
            label: "Home"
            iconSource: "../../resources/Icons/A.png"
            selected: currentIndex === 0
            onClicked: sidebar.pageSelected(0)
            index : 0 
        }

        SidebarItem {
            label: "JSON → Directory"
            iconSource: "../../resources/Icons/B.png"
            selected: currentIndex === 1
            onClicked: sidebar.pageSelected(1)
            index : 1
        }
    }
}

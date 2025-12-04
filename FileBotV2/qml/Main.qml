import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import "Components"
import "Pages"

Window {
    id: root
    visible: true
    width: 1200
    height: 800
    color: "#1e1f22"

    property int currentPage: 0

    ColumnLayout {     
        anchors.fill: parent

        Sidebar {
            onPageSelected: (pageIndex) => root.currentPage = pageIndex
            currentIndex: currentPage
        }
        Component {
            id: homePageComponent
            HomePage { }
        }

        Component {
            id: jsonPageComponent
            JsonToDirPage { }
        }

        Loader {
            id: contentLoader
            anchors.fill: parent
            sourceComponent: currentPage === 0 ? homePageComponent :
                            currentPage === 1 ? jsonPageComponent :
                            null

        }
    }
    ErrorPop {
        id: err
        anchors.bottom: parent.bottom
    }
}

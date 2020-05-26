import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        PlayersTableView{

        }

        BasketballCourtView{
        }

        Item{
        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Player List")
        }

        TabButton {
            text: qsTr("Court")
        }
        TabButton {
            text: qsTr("Statistics")
        }
    }
}

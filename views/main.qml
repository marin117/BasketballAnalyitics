import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Pick and scope")
    objectName: "mainWindow"

    signal selectedTeamChanged(int index)

    header: TabBar{
        id: headerTab
        TabButton {
            text: qsTr("Team 1")
            onClicked: {
                headerTab.setCurrentIndex(0);
                selectedTeamChanged(0);
                playerListView.model = mainModel.getPlayerModel();
            }
        }

        TabButton {
            text: qsTr("Team 2")
            onClicked: {
                headerTab.setCurrentIndex(1);
                selectedTeamChanged(1);
                playerListView.model = mainModel.getPlayerModel();
            }
        }
    }


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        PlayerListView{
            id: playerListView
            onSelectedPlayerChanged: basketballCourtView.repaintCanvas()
        }

        BasketballCourtView{
            id: basketballCourtView
        }

        Item{
        }

        Item {

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
            text: qsTr("Player Statistics")
        }
        TabButton {
            text: qsTr("Team Statistics")
        }
    }
}

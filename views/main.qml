import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Pick&Scope")
    objectName: "mainWindow"

    signal selectedTeamChanged(int index)

    header: TabBar{
        id: headerTab
        TabButton {
            text: qsTr("Team 1")
            onClicked: {
                changeTeam(0);
            }
        }

        TabButton {
            text: qsTr("Team 2")
            onClicked: {
                changeTeam(1);
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

    function changeTeam(pos){
        headerTab.setCurrentIndex(pos);
        selectedTeamChanged(pos);
        basketballCourtView.repaintCanvas();
    }
}

import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls 2.4 as ButtonControls

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
        interactive: currentIndex

        Row {
            PlayerListView{
                id: playerListView
                onSelectedPlayerChanged: basketballCourtView.repaintCanvas()
                width: parent.width / 2
                height:  parent.height
                onPlayerDoubleClicked: {
                    console.log("double click");
                    swipeView.setCurrentIndex(Tabs.TabIndexes.PlayerStatisticTab);
                }
            }
            BasketballCourtView{
                id: basketballCourtView
                width: parent.width / 2
                height:  parent.height
            }
        }

        PlayerStatistics{
            id: playerStatistics

        }

        TeamStatistics {
            id: teamStatistics

        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

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

    ButtonControls.RoundButton{
        text: "+"
        anchors.right : parent.right
        anchors.bottom: parent.bottom
        radius: 10
        onClicked: {
            console.log("Button for teams handling");
            mainModel.importTeams();
        }
    }

    function changeTeam(pos){
        headerTab.setCurrentIndex(pos);
        selectedTeamChanged(pos);
        playerListView.setToFirst();
        basketballCourtView.repaintCanvas();
    }
}

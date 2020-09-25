import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls.Material 2.12
import QtQuick.Dialogs 1.3

ApplicationWindow {

    Material.theme: Material.Dark

    visible: true
    width: 1200
    height: 780
    title: qsTr("Pick&Scope")
    objectName: "mainWindow"

    signal selectedTeamChanged(int index)

    property string timeString

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: "tmp"
        onAccepted: {
            fileDialog.close();
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
    }

    Timer {
        interval: 36000; running: true; repeat: true
        onTriggered: {
            var currentTime = new Date();
            timeString = currentTime.toLocaleTimeString(locale, "hh:mm:ss");
            console.log("export" + timeString + ".json");
            mainModel.exportTeams("export" + timeString + ".json");
        }
    }

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
            spacing: 10
            Column {
                width: parent.width * 0.58
                height:  parent.height
                spacing: 5
                PlayerListView{
                    id: playerListView
                    leftMargin: 5
                    onSelectedPlayerChanged: basketballCourtView.repaintCanvas()
                    width: parent.width
                    height:  parent.height * 0.65
                    onPlayerDoubleClicked: {
                        console.log("double click");
                        swipeView.setCurrentIndex(Tabs.TabIndexes.PlayerStatisticTab);
                    }
                }
                Flickable {
                    id: flickableTextArea
                    height: parent.height * 0.4 - footer.height
                    width: parent.width
                    leftMargin: 5
                    rightMargin: 5
                    TextArea.flickable: TextArea {
                        color: "black"
                        wrapMode: TextArea.Wrap
                        background: Rectangle {
                            color: "white"
                        }
                    }

                    ScrollBar.vertical: ScrollBar {}
                }
            }

            Column {
                width: parent.width * 0.4
                height:  parent.height
                spacing: 5
                Row {
                    width: parent.width
                    Label {
                        width: parent.width * 0.1
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Q:"
                    }

                    ComboBox {
                        id: quarterComboBox
                        width: parent.width * 0.9
                        model: [ "1", "2", "3", "4" ]
                        onCurrentIndexChanged: {
                            mainModel.selectedQuarter = currentIndex;
                        }
                    }
                }
                BasketballCourtView{
                    id: basketballCourtView
                    width: parent.width
                    height:  parent.height * 0.6
                }
                PlayerStatistics {
                    width: parent.width
                    height:  parent.height * 0.35
                    id: mainPlayerStatistics
                }
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
        id: menuButton
        text: "\u2630"
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        radius: 10
        Material.foreground: Material.Pink
        onClicked: {
            menuImportExport.open();
        }

        Menu {
            id: menuImportExport
            title: "File"
            MenuItem {
                text: "Undo"
                onTriggered: {
                    mainModel.onShotUndo();
                    basketballCourtView.repaintCanvas();
                }
            }

            MenuItem {
                text: "Import"
                onTriggered: {
                    fileDialog.open();
                }
            }
            MenuItem {
                text: "Export"
                onTriggered: {
                    mainModel.exportTeams("export.json");
                }
            }
        }
        Connections {
            target: fileDialog
            function onAccepted(){
                console.log(fileDialog.fileUrls)
                fileDialog.close();
                mainModel.importTeams(fileDialog.fileUrl);
                playerListView.setToFirst();
                selectedTeamChanged(0);
            }
        }
    }


    function changeTeam(pos){
        headerTab.setCurrentIndex(pos);
        selectedTeamChanged(pos);
        playerListView.setToFirst();
        basketballCourtView.repaintCanvas();
    }
}

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
    }

    Timer {
        interval: 60000; running: true; repeat: true
        onTriggered: {
            var currentTime = new Date();
            timeString = currentTime.toLocaleTimeString(locale, "hh:mm:ss");
            console.log("export" + timeString + ".json");
            mainModel.exportData("export" + timeString + ".json");
        }
    }

    header: TabBar{
        id: headerTab
        TabButton {
            text: mainModel.team1.name + " : " + mainModel.team1.statistics.points
            onClicked: {
                changeTeam(0);
            }
        }

        TabButton {
            text: mainModel.team2.name + " : " + mainModel.team2.statistics.points
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
                    onSelectedPlayerChanged: {
                        basketballCourtView.repaintCanvas();
                    }
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
                    clip: true
                    TextArea.flickable: TextArea {
                        id: notesArea
                        color: "black"
                        wrapMode: TextArea.Wrap
                        placeholderText: "Enter notes here...."
                        placeholderTextColor: Material.color(Material.Grey)
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
                        width: parent.width * 0.65
                        model: [ "1", "2", "3", "4", "Overtime" ]
                        onCurrentIndexChanged: {
                            mainModel.selectedQuarter = currentIndex;
                        }
                    }

                    CheckBox {
                        id: clucthCheckbox
                        tristate: false
                        checked: false
                        text: "Clutch"
                        enabled: quarterComboBox.currentIndex >= 3
                        onCheckedChanged: {
                            basketballCourtView.isClutchSelected = checked;
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

        ReportTab {
            id: reportTab
        }

        onCurrentIndexChanged: {
            if(currentIndex == 3)
                reportTab.updateCourt();
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
        TabButton{
            text: qsTr("Report")
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
                    mainModel.notes = notesArea.text;
                    mainModel.exportData("export.json");
                }
            }
        }
        Connections {
            target: fileDialog
            function onAccepted(){
                console.log(fileDialog.fileUrls)
                fileDialog.close();
                mainModel.importData(fileDialog.fileUrl);
                playerListView.setToFirst();
                //selectedTeamChanged(0);
                mainModel.onSelectedTeamChanged(0);
            }
        }

        Connections {
            target: mainModel
            function onNotesChanged(){
                notesArea.text = mainModel.notes;
            }
        }

        Connections{
            target: basketballCourtView
            function onShotAdded(){
            }
        }
    }


    function changeTeam(pos){
        headerTab.setCurrentIndex(pos);
        //selectedTeamChanged(pos);
        mainModel.onSelectedTeamChanged(pos);
        playerListView.setToFirst();
        basketballCourtView.repaintCanvas();
        reportTab.updateCourt();
    }
}

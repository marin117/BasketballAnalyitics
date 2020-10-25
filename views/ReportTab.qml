import QtQuick 2.0
import QtQuick.Controls 2.14

Item {
    Column{
        anchors.fill: parent
        spacing: 5
        Row {
            width: parent.width
            spacing: 10
            Label {
                width: parent.width * 0.05
                anchors.verticalCenter: parent.verticalCenter
                text: "Q:"
            }

            ComboBox {
                id: quarterReportComboBox
                width: parent.width * 0.2
                model: ["", "1", "2", "3", "4" ]
                onCurrentIndexChanged: {
                    if(currentIndex > 0)
                        reportCourtView.quarter = currentIndex - 1;
                    reportCourtView.repaintCanvas();
                }
            }

            Label {
                width: parent.width * 0.05
                anchors.verticalCenter: parent.verticalCenter
                text: "Players:"
            }
            ComboBox {
                id: playerCombobox
                textRole: "text"
                currentIndex: -1
                width: parent.width * 0.6
                model: mainModel.playerModel
                onCurrentIndexChanged: {
                    updateCourtView();
                }
            }
        }
        Item{
            width: parent.width
            height:  parent.height * 0.6
            BasketballCourtView {
                id: reportCourtView
                width: parent.width * 0.5
                height: parent.height
                anchors.centerIn: parent
                enabled: false
                isClutchSelected: false
                quarter: quarterReportComboBox.currentIndex
            }
        }
    }
    function updateCourtView(){
        if(playerCombobox.currentIndex > -1){
            reportCourtView.shots = mainModel.playerModel.getPlayerAt(playerCombobox.currentIndex).shots;
            reportCourtView.repaintCanvas();
        }
    }
}


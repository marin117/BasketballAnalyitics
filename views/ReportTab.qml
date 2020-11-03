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
                model: ["", "1", "2", "3", "4", "Overtime" ]
                onCurrentIndexChanged: {
                    reportCourtView.quarter = currentIndex - 1 ;
                    reportCourtView.repaintCanvas();
                }
            }

            Label {
                width: parent.width * 0.05
                anchors.verticalCenter: parent.verticalCenter
                text: "Property:"
            }
            ComboBox {
                id: propertyCombobox
                textRole: "text"
                currentIndex: 0
                width: parent.width * 0.6
                model: ["", "..."]
                onCurrentIndexChanged: {
                    reportCourtView.repaintCanvas();
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
                quarter: quarterReportComboBox.currentIndex - 1
            }
        }
        PlayerStatistics{
            width: parent.width
            height:  parent.height * 0.6
            controlVisible: false
            quarter: quarterReportComboBox.currentIndex - 1
        }
    }
}


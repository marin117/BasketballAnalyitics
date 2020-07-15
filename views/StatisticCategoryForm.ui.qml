import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Item {
    id: statisticElement
    implicitWidth: parent.width
    implicitHeight: 50
    property alias categoryValueText: categoryValueText
    property alias increaseButton: increaseButton
    property alias decreaseButton: decreaseButton
    property alias controlRowVisible: controlsRow.visible

    property string categoryName: "Category"
    property string categoryVal
    property alias textValue: categoryValueText.text

    Row {
        id: rowLayout
        anchors.fill: parent
        transformOrigin: Item.Center

        //anchors.fill: parent
        //Layout.fillWidth: true
        Item {
            height: parent.height
            width: parent.width / 3
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                id: categoryNameText
                text: categoryName
                font.pixelSize: 12
            }
        }
        Item {
            width: parent.width / 3
            height: parent.height
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                id: categoryValueText
                //text: mainModel.playerStatistics[categoryVal]
                font.pixelSize: 12
            }
        }
        Item {
            width: parent.width / 3
            height: parent.height
            Row {
                id: controlsRow
                anchors.right: parent.right
                RoundButton {
                    id: increaseButton
                    text: "+"
                }

                RoundButton {
                    id: decreaseButton
                    text: "-"
                    enabled: categoryVal > 0
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_width:360}
}
##^##*/


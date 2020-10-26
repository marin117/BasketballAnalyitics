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

    property var rootColor: "grey"
    Row {
        id: rowLayout
        anchors.fill: parent
        transformOrigin: Item.Center
        anchors.topMargin: 8
        //anchors.fill: parent
        //Layout.fillWidth: true
        Item {
            height: parent.height
            width: parent.width / 3
            Text {
                anchors.centerIn: parent
                id: categoryNameText
                text: categoryName
                font.pixelSize: 16
                font.family: "Roboto"
                color: rootColor
            }
        }
        Item {
            width: parent.width / 3
            height: parent.height
            Text {
                anchors.centerIn: parent
                id: categoryValueText
                //text: mainModel.playerStatistics[categoryVal]
                font.pixelSize: 16
                font.family: "Roboto"
                color: rootColor
            }
        }
        Item {
            width: parent.width / 3
            height: parent.height
            Row {
                id: controlsRow
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                RoundButton {
                    id: increaseButton
                    text: "+"
                    focusPolicy: Qt.NoFocus
                }

                RoundButton {
                    id: decreaseButton
                    text: "-"
                    enabled: categoryVal > 0
                    focusPolicy: Qt.NoFocus
                }
            }
        }
    }
    Rectangle {
        implicitWidth: parent.width
        implicitHeight: 1
        color: rootColor
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

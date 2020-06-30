import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Item {
    id: statisticElement
    width: 400
    height: 50
    property alias categoryValueText: categoryValueText
    property alias increaseButton: increaseButton
    property alias decreaseButton: decreaseButton

    property string categoryName: "Category"
    property string categoryVal

    RowLayout {
        id: rowLayout
        anchors.fill: parent
        Layout.fillWidth: true

        Text {
            id: categoryNameText
            text: categoryName
            font.pixelSize: 12
        }

        Text {
            id: categoryValueText
            text: mainModel.playerStatistics[categoryVal]
            font.pixelSize: 12
        }

        Row {
            id: controlsRow
            width: 100
            height: 50

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

import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import PlayerTableModel 0.1

TableView {
    backgroundVisible: false
    selectionMode: SelectionMode.SingleSelection

    model: playerModel

    TableViewColumn {
        role: "number"
        title: "#"
        width: 200
        delegate : TextField {
            textColor: "black"
            text: styleData.value
            onAccepted: {
                playerModel.number = text
                console.log(playerModel.number)

            }
        }
    }

    TableViewColumn {
        role: "name"
        title: "Name"
        width: 200
        delegate : TextField {
            textColor: "black"
            text: styleData.value
            onAccepted: {
                playerModel.name = text
                console.log(playerModel.name)
            }
        }
    }

    TableViewColumn {
        role: "surname"
        title: "Surname"
        width: 200
        delegate : TextField {
            textColor: "black"
            text: styleData.value
            onAccepted: {
                playerModel.surname = text
                console.log(playerModel.surname)
            }
        }

    }

    style: TableViewStyle{
        alternateBackgroundColor: "transparent"
        textColor: "black"
    }

    ButtonControls.RoundButton{
        text: "+"
        anchors.right : parent.right
        anchors.bottom: parent.bottom
        radius: 10
        onClicked: {
            playerModel.insertRows(playerModel.rowCount(), 1)
        }
    }

}

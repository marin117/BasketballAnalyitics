import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import PlayerTableModel 0.1

ListView {
//    backgroundVisible: false
    //selectionMode: SelectionMode.SingleSelection

    model: playerModel

    delegate: RowLayout{
        spacing: 10
        TextField {
            text: model.number
            onTextChanged: model.number = text
            style : TextFieldStyle {
                textColor: 'black'
            }
        }
        TextField {
            text: model.name
            onTextChanged: model.name = text
            style : TextFieldStyle {
                textColor: 'black'
            }
        }
        TextField {
            text: model.surname
            onTextChanged: model.surname = text
            style : TextFieldStyle {
                textColor: 'black'
            }
        }

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

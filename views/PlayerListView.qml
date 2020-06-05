import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import PlayerListModel 0.1

ListView {
    id: playerList
    model: mainModel.getPlayerModel()
    highlight: Rectangle { color: "maroon"; radius: 5 }
    objectName: "playerListObject"

    signal selectedPlayerChanged(pos: int)
    delegate: Component{
        Item {
            //        spacing: 10
            width: parent.width; height: 40
            RowLayout{
                height: 40
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
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    playerList.currentIndex = index;
                    selectedPlayerChanged(index);
                }
            }

        }
    }
    focus: true

    ButtonControls.RoundButton{
        text: "+"
        anchors.right : parent.right
        anchors.bottom: parent.bottom
        radius: 10
        onClicked: {
            mainModel.getPlayerModel().insertRows(mainModel.getPlayerModel().rowCount(), 1)
        }
    }

}

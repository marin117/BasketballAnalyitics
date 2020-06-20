import QtQuick 2.14
import QtQuick.Controls 1.4
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
                Label {
                    text: model.number
                }
                Label {
                    text: model.name
                }
                Label {
                    text: model.surname
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

}

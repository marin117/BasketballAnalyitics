import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import PlayerListModel 0.1
import QtQuick.Controls.Material 2.3

ListView {
    id: playerList
    model: mainModel.playerModel
    highlight: Rectangle {
        color: Material.color(Material.Blue, Material.Blue)
        radius: 5
    }
    objectName: "playerListObject"

    signal selectedPlayerChanged(pos: int)
    signal playerDoubleClicked()
    width: parent.width
    delegate: Component{
        Item {
            //        spacing: 10
            width: playerList.width;
            height: 40
            RowLayout{
                height: 40
                Label {
                    font.pixelSize: 18
                    font.family: "Roboto"
                    color: Material.color(Material.Pink, Material.Pink)
                    text: model.text
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    playerList.currentIndex = index;
                    selectedPlayerChanged(index);
                }

                onDoubleClicked: {
                    playerDoubleClicked();
                }
            }

        }
    }
    focus: true

    function setToFirst(){
        selectedPlayerChanged(0);
        playerList.currentIndex = 0;
    }

}

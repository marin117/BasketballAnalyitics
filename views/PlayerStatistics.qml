import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls


Item {
    Grid {
       // anchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenter: parent.verticalCenter
        anchors.fill: parent
        columns: 3
        spacing: 6

        Item {
            width: parent.width/3; height: 50
            Text {
                text: qsTr("Points")
            }
        }
        Item {
            id: pointsNumItem
            width: parent.width/3; height: 50
            Text {
                id: pointsNum
                text: mainModel.playerStatistics.points
            }
        }
        Item {
            width: parent.width/3; height: 50
            Row {
                ButtonControls.RoundButton {
                    id: addPointsButton
                    text: qsTr("+")
                    onClicked: {
                        mainModel.playerStatistics.points += 1;
                        console.log(mainModel.playerStatistics.points);
                        pointsNum.text = mainModel.playerStatistics.points;
                        decreasePointsButton.enabled = true;
                    }
                }
                ButtonControls.RoundButton{
                    id: decreasePointsButton
                    text: qsTr("-")
                    enabled: mainModel.playerStatistics.points > 0
                    onClicked: {
                        mainModel.playerStatistics.points -= 1;
                        pointsNum.text = mainModel.playerStatistics.points;
                        if (mainModel.playerStatistics.points <= 0){
                            this.enabled = false;
                        }
                    }
                }


            }
        }
    }
}

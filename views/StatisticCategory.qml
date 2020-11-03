import QtQuick 2.4
import QtQuick.Controls.Material 2.12

StatisticCategoryForm {
    rootColor: Material.color(Material.Grey)
    implicitWidth: parent.width
    property bool isTeam : false
    property int  quarter: -1
    Connections {
        target: increaseButton
        function onClicked() {
            mainModel.playerStatistics[categoryVal] += 1;
            mainModel.teamStatistics[categoryVal] += 1;
            mainModel.playerQuarterStatistics[categoryVal] += 1;
            decreaseButton.enabled = true;
            if(quarter < 0){
                if(!isTeam)
                    textValue = mainModel.playerStatistics[categoryVal];
                else
                    textValue = mainModel.teamStatistics[categoryVal];
            }
            else{
                textValue = mainModel.selectedPlayer.quarterStatistics[quarter][categoryVal];
            }

            console.log(categoryVal + "   " + mainModel.teamStatistics[categoryVal]);
        }
    }

    Connections {
        target: decreaseButton
        function onClicked(){
            mainModel.playerStatistics[categoryVal] -= 1;
            mainModel.teamStatistics[categoryVal] -= 1;
            mainModel.playerQuarterStatistics[categoryVal] -= 1;
            if (mainModel.playerStatistics[categoryVal] <= 0){
                decreaseButton.enabled = false;
            }
            if(quarter < 0){
                if(!isTeam)
                    textValue = mainModel.playerStatistics[categoryVal];
                else
                    textValue = mainModel.teamStatistics[categoryVal];
            }
            else{
                textValue = mainModel.selectedPlayer.quarterStatistics[quarter][categoryVal];
            }
        }

    }

    Connections {
        target: mainModel
        function onSelectedPlayerChanged(){
            if(quarter < 0){
                if(!isTeam)
                    textValue = mainModel.playerStatistics[categoryVal];
                else
                    textValue = mainModel.teamStatistics[categoryVal];
            }
            else{
                textValue = mainModel.selectedPlayer.quarterStatistics[quarter][categoryVal];
            }
        }
    }

    Connections {
        target: mainModel
        function onTeamStatisticsChanged(){
            if(isTeam)
                textValue = mainModel.teamStatistics[categoryVal];
        }
    }

    Binding {
        target: categoryValueText
        property: "text"
        value: if (!isTeam && quarter < 0) mainModel.playerStatistics[categoryVal]
    }

    Binding{
        target: categoryValueText
        property: "text"
        value: if (isTeam) mainModel.teamStatistics[categoryVal]
    }

    Binding{
        target: categoryValueText
        property: "text"
        value: if (quarter >= 0) mainModel.selectedPlayer.quarterStatistics[quarter][categoryVal]
    }
}

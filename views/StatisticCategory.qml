import QtQuick 2.4

StatisticCategoryForm {
    implicitWidth: parent.width
    property bool isTeam : false
    Connections {
        target: increaseButton
        function onClicked() {
            mainModel.playerStatistics[categoryVal] += 1;
            mainModel.teamStatistics[categoryVal] += 1;
            decreaseButton.enabled = true;
            if(!isTeam)
                textValue = mainModel.playerStatistics[categoryVal];
            else
                textValue = mainModel.teamStatistics[categoryVal];
            console.log(categoryVal + "   " + mainModel.teamStatistics[categoryVal]);
            mainModel.teamStatistics[categoryVal + "Changed"]();

        }
    }

    Connections {
        target: decreaseButton
        function onClicked(){
            mainModel.playerStatistics[categoryVal] -= 1;
            mainModel.teamStatistics[categoryVal] -= 1;
            if (mainModel.playerStatistics[categoryVal] <= 0){
                decreaseButton.enabled = false;
            }
            if(!isTeam)
                textValue = mainModel.playerStatistics[categoryVal];
            else
                textValue = mainModel.teamStatistics[categoryVal];
        }
    }

    Connections {
        target: mainModel
        function onSelectedPlayerChanged(){
            if (!isTeam)
                textValue = mainModel.playerStatistics[categoryVal];
            else{
                textValue = mainModel.teamStatistics[categoryVal];
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
        value: if (!isTeam) mainModel.playerStatistics[categoryVal]
    }

    Binding{
        target: categoryValueText
        property: "text"
        value: if (isTeam) mainModel.teamStatistics[categoryVal]
    }

}

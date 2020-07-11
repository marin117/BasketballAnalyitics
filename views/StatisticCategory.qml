import QtQuick 2.4

StatisticCategoryForm {
    implicitWidth: parent.width
    Connections {
        target: increaseButton
        function onClicked() {
            mainModel.playerStatistics[categoryVal] += 1;
            decreaseButton.enabled = true;
            categoryValueText.text = mainModel.playerStatistics[categoryVal];
        }
    }

    Connections {
        target: decreaseButton
        function onClicked(){
            mainModel.playerStatistics[categoryVal] -= 1;
            if (mainModel.playerStatistics[categoryVal] <= 0){
                decreaseButton.enabled = false;
            }
            categoryValueText.text = mainModel.playerStatistics[categoryVal];
        }
    }

    Connections {
        target: mainModel
        function onSelectedPlayerChanged(){
            categoryValueText.text = mainModel.playerStatistics[categoryVal];
        }
    }
    Binding {
        target: categoryValueText
        property: "text"
        value: mainModel.playerStatistics[categoryVal]
    }
}

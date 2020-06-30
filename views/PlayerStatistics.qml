import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls


Item {
    StatisticCategory {
        id: pointsCategory
        categoryName: "Points"
        categoryVal: "points"

        Connections {
            target: mainModel
            function onStatisticsChanged(){
                pointsCategory.categoryValueText.text = mainModel.playerStatistics[pointsCategory.categoryVal]

            }

            function onSelectedPlayerChanged(){
                pointsCategory.categoryValueText.text = mainModel.playerStatistics["points"]

            }
        }
    }

}

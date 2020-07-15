import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls


Item {
    ColumnLayout {
        width: parent.width
        StatisticCategory {
            id: pointsCategory
            categoryName: "Points"
            categoryVal: "points"
            textValue: mainModel.playerStatistics[categoryVal]
        }

        StatisticCategory {
            id: shotsNumCategory
            categoryName: "Shots"
            categoryVal: "shotsNum"
            controlRowVisible: false
            textValue: mainModel.playerStatistics[categoryVal]

        }

        StatisticCategory {
            id: shotsScoredCategory
            categoryName: "Shots scored"
            categoryVal: "shotsScored"
            controlRowVisible: false
            textValue: mainModel.playerStatistics[categoryVal]

        }

        StatisticCategory {
            id: stealsCategory
            categoryName: "Steals"
            categoryVal: "steals"
            textValue: mainModel.playerStatistics[categoryVal]
        }

        StatisticCategory {
            id: offensiveReboundsCategory
            categoryName: "Offensive Rebounds"
            categoryVal: "offensiveRebounds"
            textValue: mainModel.playerStatistics[categoryVal]

        }

        StatisticCategory {
            id: defensiveReboundsCategory
            categoryName: "Defensive Rebounds"
            categoryVal: "defensiveRebounds"
            textValue: mainModel.playerStatistics[categoryVal]

        }


        StatisticCategory {
            id: assitsCategory
            categoryName: "Assists"
            categoryVal: "assists"
            textValue: mainModel.playerStatistics[categoryVal]

        }


        StatisticCategory {
            id: blocksCategory
            categoryName: "Blocks"
            categoryVal: "blocks"
            textValue: mainModel.playerStatistics[categoryVal]

        }

        StatisticCategory {
            id: turnoversCategory
            categoryName: "Turnovers"
            categoryVal: "turnovers"
            textValue: mainModel.playerStatistics[categoryVal]

        }

    }
}



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
        }

        StatisticCategory {
            id: shotsNumCategory
            categoryName: "Shots"
            categoryVal: "shotsNum"
            controlRowVisible: false
        }

        StatisticCategory {
            id: shotsScoredCategory
            categoryName: "Shots scored"
            categoryVal: "shotsScored"
            controlRowVisible: false
        }

        StatisticCategory {
            id: stealsCategory
            categoryName: "Steals"
            categoryVal: "steals"
        }

        StatisticCategory {
            id: offensiveReboundsCategory
            categoryName: "Offensive Rebounds"
            categoryVal: "offensiveRebounds"
        }

        StatisticCategory {
            id: defensiveReboundsCategory
            categoryName: "Defensive Rebounds"
            categoryVal: "defensiveRebounds"
        }


        StatisticCategory {
            id: assitsCategory
            categoryName: "Assists"
            categoryVal: "assists"
        }


        StatisticCategory {
            id: blocksCategory
            categoryName: "Blocks"
            categoryVal: "blocks"
        }

        StatisticCategory {
            id: turnoversCategory
            categoryName: "Turnovers"
            categoryVal: "turnovers"
        }

    }
}



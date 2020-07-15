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
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }

        StatisticCategory {
            id: shotsNumCategory
            categoryName: "Shots"
            categoryVal: "shotsNum"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }

        StatisticCategory {
            id: shotsScoredCategory
            categoryName: "Shots scored"
            categoryVal: "shotsScored"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }

        StatisticCategory {
            id: stealsCategory
            categoryName: "Steals"
            categoryVal: "steals"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }

        StatisticCategory {
            id: offensiveReboundsCategory
            categoryName: "Offensive Rebounds"
            categoryVal: "offensiveRebounds"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }

        StatisticCategory {
            id: defensiveReboundsCategory
            categoryName: "Defensive Rebounds"
            categoryVal: "defensiveRebounds"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }


        StatisticCategory {
            id: assitsCategory
            categoryName: "Assists"
            categoryVal: "assists"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }


        StatisticCategory {
            id: blocksCategory
            categoryName: "Blocks"
            categoryVal: "blocks"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }

        StatisticCategory {
            id: turnoversCategory
            categoryName: "Turnovers"
            categoryVal: "turnovers"
            isTeam: true
            controlRowVisible: false
            textValue: mainModel.teamStatistics[categoryVal]
        }
    }
}



import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls 2.15 as ScrollViewCtl


Item {
    ScrollViewCtl.ScrollView{
        id: teamStatisticsScrollView
        anchors.fill: parent
        ColumnLayout {
            id: teamStatisticsColumn
            width: Math.max(implicitWidth, playerStatisticsScrollView.availableWidth)
            StatisticCategory {
                id: pointsCategory
                categoryName: "Points"
                categoryVal: "points"
                isTeam: true
                controlRowVisible: false
                textValue: mainModel.teamStatistics[categoryVal]
            }

            StatisticCategory {
                id: shotsScoredCategory
                categoryName: "FGM"
                categoryVal: "shotsScored"
                isTeam: true
                controlRowVisible: false
                textValue: mainModel.teamStatistics[categoryVal]
            }

            StatisticCategory {
                id: shotsNumCategory
                categoryName: "FGA"
                categoryVal: "shotsNum"
                isTeam: true
                controlRowVisible: false
                textValue: mainModel.teamStatistics[categoryVal]
            }

            StatisticCategory {
                id: threePointsMadeCategory
                categoryName: "3PTM"
                categoryVal: "threePointsMade"
                controlRowVisible: false
                isTeam: true
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: threePointsNumCategory
                categoryName: "3PTA"
                categoryVal: "threePointsNum"
                controlRowVisible: false
                isTeam: true
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: freeThrowsMadeCategory
                categoryName: "Free Throws Made"
                categoryVal: "freeThrowsMade"
                isTeam: true
                controlRowVisible: false
                textValue: mainModel.teamStatistics[categoryVal]

            }

            StatisticCategory {
                id: freeThrows
                categoryName: "Free Throws"
                categoryVal: "freeThrows"
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

            StatisticCategory {
                id: foulsCategory
                categoryName: "Fouls"
                categoryVal: "fouls"
                isTeam: true
                controlRowVisible: false
                textValue: mainModel.teamStatistics[categoryVal]
            }
        }
        onWidthChanged: {
            teamStatisticsColumn.width = parent.width;
        }
    }

}



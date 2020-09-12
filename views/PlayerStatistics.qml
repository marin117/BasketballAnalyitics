import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls 2.15 as ScrollViewCtl


Item {
    ScrollViewCtl.ScrollView{
        id: playerStatisticsScrollView
        anchors.fill: parent
        Column {
            id: playerStatisticsColumn
            width: Math.max(implicitWidth, playerStatisticsScrollView.availableWidth)
            StatisticCategory {
                id: pointsCategory
                categoryName: "Points"
                categoryVal: "points"
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: shotsNumCategory
                categoryName: "FGA"
                categoryVal: "shotsNum"
                controlRowVisible: false
                textValue: mainModel.playerStatistics[categoryVal]

            }

            StatisticCategory {
                id: shotsScoredCategory
                categoryName: "FGM"
                categoryVal: "shotsScored"
                controlRowVisible: false
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: freeThrowsMadeCategory
                categoryName: "Free Throws Made"
                categoryVal: "freeThrowsMade"
                textValue: mainModel.playerStatistics[categoryVal]
                onTextValueChanged: {
                    freeThrows.textValue = mainModel.playerStatistics.freeThrows;
                    pointsCategory.textValue = mainModel.playerStatistics.points;
                }
            }

            StatisticCategory {
                id: freeThrows
                categoryName: "Free Throws"
                categoryVal: "freeThrows"
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
        onWidthChanged: {
            playerStatisticsColumn.width = parent.width;
        }
    }
}



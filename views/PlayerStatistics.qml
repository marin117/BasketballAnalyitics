import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls
import QtQuick.Controls 2.15 as ScrollViewCtl


Item {
    id: root
    property bool controlVisible: true
    property int quarter: -1

    ScrollViewCtl.ScrollView{
        id: playerStatisticsScrollView
        anchors.fill: parent
        clip : true
        Column {
            id: playerStatisticsColumn
            width: Math.max(implicitWidth, playerStatisticsScrollView.availableWidth)
            StatisticCategory {
                id: pointsCategory
                categoryName: "Points"
                categoryVal: "points"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: false
                quarter: root.quarter
            }

            StatisticCategory {
                id: shotsScoredCategory
                categoryName: "FGM"
                categoryVal: "shotsScored"
                controlRowVisible: false
                quarter: root.quarter
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: shotsNumCategory
                categoryName: "FGA"
                categoryVal: "shotsNum"
                controlRowVisible: false
                quarter: root.quarter
                textValue: mainModel.playerStatistics[categoryVal]

            }

            StatisticCategory {
                id: threePointsMadeCategory
                categoryName: "3PTM"
                categoryVal: "threePointsMade"
                controlRowVisible: false
                quarter: root.quarter
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: threePointsNumCategory
                categoryName: "3PTA"
                categoryVal: "threePointsNum"
                controlRowVisible: false
                quarter: root.quarter
                textValue: mainModel.playerStatistics[categoryVal]
            }

            StatisticCategory {
                id: freeThrowsMadeCategory
                categoryName: "FTM"
                categoryVal: "freeThrowsMade"
                textValue: mainModel.playerStatistics[categoryVal]
                onTextValueChanged: {
                    if(quarter < 0){
                        freeThrowsCategory.textValue = mainModel.playerStatistics.freeThrows;
                        pointsCategory.textValue = mainModel.playerStatistics.points;
                        if(mainModel.playerStatistics.freeThrows)
                            freeThrowsCategory.decreaseButton.enabled = true;
                    }
                }
                controlRowVisible: controlVisible
                quarter: root.quarter
            }

            StatisticCategory {
                id: freeThrowsCategory
                categoryName: "FTA"
                categoryVal: "freeThrows"
                textValue: mainModel.playerStatistics[categoryVal]
                onTextValueChanged: {
                    if(quarter < 0){
                        if(mainModel.playerStatistics[categoryVal] < mainModel.playerStatistics.freeThrowsMade){
                            freeThrowsMadeCategory.textValue = mainModel.playerStatistics.freeThrowsMade;
                            pointsCategory.textValue = mainModel.playerStatistics.points;
                        }
                        if(mainModel.playerStatistics[categoryVal] === 0)
                            freeThrowsMadeCategory.decreaseButton.enabled = false;
                    }
                }
                controlRowVisible: controlVisible
                quarter: root.quarter
            }

            StatisticCategory {
                id: stealsCategory
                categoryName: "Steals"
                categoryVal: "steals"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter
            }

            StatisticCategory {
                id: offensiveReboundsCategory
                categoryName: "Offensive Rebounds"
                categoryVal: "offensiveRebounds"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter

            }

            StatisticCategory {
                id: defensiveReboundsCategory
                categoryName: "Defensive Rebounds"
                categoryVal: "defensiveRebounds"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter

            }


            StatisticCategory {
                id: assitsCategory
                categoryName: "Assists"
                categoryVal: "assists"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter
            }


            StatisticCategory {
                id: blocksCategory
                categoryName: "Blocks"
                categoryVal: "blocks"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter
            }

            StatisticCategory {
                id: turnoversCategory
                categoryName: "Turnovers"
                categoryVal: "turnovers"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter

            }


            StatisticCategory {
                id: foulsCategory
                categoryName: "Fouls"
                categoryVal: "fouls"
                textValue: mainModel.playerStatistics[categoryVal]
                controlRowVisible: controlVisible
                quarter: root.quarter
            }

        }
        onWidthChanged: {
            playerStatisticsColumn.width = parent.width;
        }
    }
}



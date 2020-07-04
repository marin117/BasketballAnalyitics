import QtQuick 2.0
import Statistics 0.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as ButtonControls


Item {
    ColumnLayout {
        StatisticCategory {
            id: pointsCategory
            categoryName: "Points"
            categoryVal: "points"
        }

        StatisticCategory {
            id: stealsCategory
            categoryName: "Steals"
            categoryVal: "steals"
        }
    }
}



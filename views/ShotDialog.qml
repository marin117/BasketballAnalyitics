import QtQuick 2.0
import QtQuick.Controls 2.3

Dialog {
    id: shotDialog
    title: "Shot properties"
    standardButtons: Dialog.Ok | Dialog.Cancel
    modal: true
    property bool isMiss : false
    property bool isContested: false
    property bool isThree: false
    property bool isOffhand : false
    property bool isOffTheDribble : false
    property bool isCatchAndShoot : false
    property bool isPickAndRoll : false
    property bool isPickAndPop : false
    property bool isPost : false
    property bool isMismatch : false
    property bool isIso : false
    property bool isLayup : false
    property bool isFaul : false
    property bool isTransition : false
    property bool isDunk: false
    property bool isFloater: false
    property bool isEurostep: false
    property bool isPutback: false
    property bool isSecondChance: false
    property bool isOffTurnover: false

    anchors.centerIn: parent

    ScrollView{
        anchors.fill: parent
        Grid {
            columns: 3
            CheckBox {
                id: isMissCheck
                checked: isMiss
                text: "Miss"
                tristate: false
                onCheckStateChanged: isMiss = checkState;

            }

            CheckBox {
                id: isContestedCheck
                checked: isContested
                text: "Contested"
                tristate: false
                onCheckStateChanged: isContested = checkState;

            }

            CheckBox {
                id: isThreeCheck
                checked: isThree
                text: "For three"
                tristate: false
                onCheckStateChanged: isThree = checkState;

            }

            CheckBox {
                id: isOffhandCheck
                checked: isOffhand
                text: "Off hand"
                tristate: false
                onCheckStateChanged: isOffhand = checkState;

            }
            CheckBox {
                id: isOffTheDribbleCheck
                checked: isOffTheDribble
                text: "Off the dribble"
                tristate: false
                onCheckStateChanged: isOffTheDribble = checkState;

            }
            CheckBox {
                id: isCatchAndShootCheck
                checked: isCatchAndShoot
                text: "Catch and Shoot"
                tristate: false
                onCheckStateChanged: isCatchAndShoot = checkState;

            }
            CheckBox {
                id: isPickAndRollCheck
                checked: isPickAndRoll
                text: "Pick and Roll"
                tristate: false
                onCheckStateChanged: isPickAndRoll = checkState;

            }
            CheckBox {
                id: isPickAndPopCheck
                checked: isPickAndPop
                text: "Pick and Pop"
                tristate: false
                onCheckStateChanged: isPickAndPop = checkState;

            }
            CheckBox {
                id: isPostCheck
                checked: isPost
                text: "Post"
                tristate: false
                onCheckStateChanged: isPost = checkState;

            }
            CheckBox {
                id: isMismatchCheck
                checked: isMismatch
                text: "Missmatch"
                tristate: false
                onCheckStateChanged: isMismatch = checkState;

            }
            CheckBox {
                id: isIsoCheck
                checked: isIso
                text: "Isolation"
                tristate: false
                onCheckStateChanged: isIso = checkState;

            }
            CheckBox {
                id: isLayupCheck
                checked: isLayup
                text: "Layup"
                tristate: false
                onCheckStateChanged: isLayup = checkState;

            }

            CheckBox {
                id: isDunkCheck
                checked: isDunk
                text: "Dunk"
                tristate: false
                onCheckStateChanged: isDunk = checkState;

            }

            CheckBox {
                id: isFloaterCheck
                checked: isFloater
                text: "Floater"
                tristate: false
                onCheckStateChanged: isFloater = checkState;

            }

            CheckBox {
                id: isEurostepCheck
                checked: isEurostep
                text: "Eurostep"
                tristate: false
                onCheckStateChanged: isEurostep = checkState;

            }

            CheckBox {
                id: isPutbackCheck
                checked: isPutback
                text: "Putback"
                tristate: false
                onCheckStateChanged: isPutback = checkState;
            }

            CheckBox {
                id: isSecondChanceCheck
                checked: isSecondChance
                text: "Second chance"
                tristate: false
                onCheckStateChanged: isSecondChance = checkState;
            }

            CheckBox {
                id: isFaulCheck
                checked: isFaul
                text: "Faul"
                tristate: false
                onCheckStateChanged: isFaul = checkState;
            }
            CheckBox {
                id: isTransitionCheck
                checked: isTransition
                text: "Transition"
                tristate: false
                onCheckStateChanged: isTransition = checkState;
            }

            CheckBox {
                id: isOffTurnoverCheck
                checked: isOffTurnover
                text: "Off Turnover"
                tristate: false
                onCheckStateChanged: isOffTurnover = checkState;
            }
        }
    }
}


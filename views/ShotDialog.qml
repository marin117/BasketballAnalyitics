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
    property bool isClutch: false
    property bool isDunk: false

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
            }

            CheckBox {
                id: isContestedCheck
                checked: isContested
                text: "Contested"
                tristate: false
            }

            CheckBox {
                id: isThreeCheck
                checked: isThree
                text: "For three"
                tristate: false
            }

            CheckBox {
                id: isOffhandCheck
                checked: isOffhand
                text: "Off hand"
                tristate: false
            }
            CheckBox {
                id: isOffTheDribbleCheck
                checked: isOffTheDribble
                text: "Off the dribble"
                tristate: false
            }
            CheckBox {
                id: isCatchAndShootCheck
                checked: isCatchAndShoot
                text: "Catch and Shoot"
                tristate: false
            }
            CheckBox {
                id: isPickAndRollCheck
                checked: isPickAndRoll
                text: "Pick and Roll"
                tristate: false
            }
            CheckBox {
                id: isPickAndPopCheck
                checked: isPickAndPop
                text: "Pick and Pop"
                tristate: false
            }
            CheckBox {
                id: isPostCheck
                checked: isPost
                text: "Post"
                tristate: false
            }
            CheckBox {
                id: isMismatchCheck
                checked: isMismatch
                text: "Missmatch"
                tristate: false
            }
            CheckBox {
                id: isIsoCheck
                checked: isIso
                text: "Isolation"
                tristate: false
            }
            CheckBox {
                id: isLayupCheck
                checked: isLayup
                text: "Layup"
                tristate: false
            }

            CheckBox {
                id: isDunkCheck
                checked: isDunk
                text: "Dunk"
                tristate: false
            }

            CheckBox {
                id: isFaulCheck
                checked: isFaul
                text: "Faul"
                tristate: false
            }
            CheckBox {
                id: isTransitionCheck
                checked: isTransition
                text: "Transition"
                tristate: false
            }

            CheckBox {
                id: isClutchCheck
                checked: isClutch
                text: "Clutch"
                tristate: false
            }
        }
    }


    onAccepted: {
        console.log("Ok clicked");
        isMiss = isMissCheck.checkState;
        isContested = isContestedCheck.checkState;
        isThree = isThreeCheck.checkState;
        isOffhand = isOffhandCheck.checkState;
        isOffTheDribble = isOffTheDribbleCheck.checkState;
        isCatchAndShoot = isCatchAndShootCheck.checkState;
        isPickAndRoll = isPickAndRollCheck.checkState;
        isPickAndPop = isPickAndPopCheck.checkState;
        isPost = isPostCheck.checkState;
        isMismatch = isMismatchCheck.checkState;
        isIso = isIsoCheck.checkState;
        isLayup = isLayupCheck.checkState;
        isFaul = isFaulCheck.checkState;
        isTransition = isTransitionCheck.checkState;
        isClutch = isClutchCheck.checkState;
        isDunk = isDunkCheck.checkState;
    }
    onRejected: {
        console.log("Cancel clicked");
    }
}


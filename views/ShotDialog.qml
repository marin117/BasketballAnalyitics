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

    anchors.centerIn: parent

    ScrollView{
        anchors.fill: parent
        Grid {
            columns: 3
            CheckBox {
                id: isMissCheck
                checked: false
                text: "Miss"
                tristate: false
            }

            CheckBox {
                id: isContestedCheck
                checked: false
                text: "Contested"
                tristate: false
            }

            CheckBox {
                id: isThreeCheck
                checked: false
                text: "For three"
                tristate: false
            }

            CheckBox {
                id: isOffhandCheck
                checked: false
                text: "Off hand"
                tristate: false
            }
            CheckBox {
                id: isOffTheDribbleCheck
                checked: false
                text: "Off the dribble"
                tristate: false
            }
            CheckBox {
                id: isCatchAndShootCheck
                checked: false
                text: "Catch and Shoot"
                tristate: false
            }
            CheckBox {
                id: isPickAndRollCheck
                checked: false
                text: "Pick and Roll"
                tristate: false
            }
            CheckBox {
                id: isPickAndPopCheck
                checked: false
                text: "Pick and Pop"
                tristate: false
            }
            CheckBox {
                id: isPostCheck
                checked: false
                text: "Post"
                tristate: false
            }
            CheckBox {
                id: isMismatchCheck
                checked: false
                text: "Missmatch"
                tristate: false
            }
            CheckBox {
                id: isIsoCheck
                checked: false
                text: "Isolation"
                tristate: false
            }
            CheckBox {
                id: isLayupCheck
                checked: false
                text: "Layup"
                tristate: false
            }
            CheckBox {
                id: isFaulCheck
                checked: false
                text: "Faul"
                tristate: false
            }
            CheckBox {
                id: isTransitionCheck
                checked: false
                text: "Transition"
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
    }
    onRejected: {
        console.log("Cancel clicked");
    }
}


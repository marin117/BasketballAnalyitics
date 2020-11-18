import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12
import Shot 0.1

Dialog {
    id: shotDialog
    title: "Shot properties"
    standardButtons: Dialog.Ok | Dialog.Cancel
    modal: true
    clip: true

//    contentWidth: scroll.contentWidth
//    contentHeight: scroll.contentHeight
//    property bool isMiss : false
//    property bool isContested: false
//    property bool isThree: false
//    property bool isOffhand : false
//    property bool isOffTheDribble : false
//    property bool isCatchAndShoot : false
//    property bool isPickAndRoll : false
//    property bool isPickAndPop : false
//    property bool isPost : false
//    property bool isMismatch : false
//    property bool isIso : false
//    property bool isLayup : false
//    property bool isFaul : false
//    property bool isTransition : false
//    property bool isDunk: false
//    property bool isFloater: false
//    property bool isEurostep: false
//    property bool isPutback: false
//    property bool isSecondChance: false
//    property bool isOffTurnover: false

    property var shot: paramShot

    Shot {
        id: paramShot
    }

    anchors.centerIn: parent


   ScrollView {
        id: scroll
        clip : true
        anchors.fill: parent
        Column{
            id: grids
            width: shotDialog.width * 0.92
            height: shotDialog.height
            Grid{
                columns: 3
                width: parent.width
                Repeater {
                    model: propModel
                    delegate: CheckBox {
                        text: name
                        width: parent.width / 3
                        checked: paramShot[value]
                        onCheckedChanged: paramShot[value] = checked;
                    }
                }
            }
            Rectangle {
                implicitWidth: parent.width
                implicitHeight: 1
                color: "grey"
            }
            Grid{
                columns: 3
                width: parent.width
                Repeater {
                    model: shotProp
                    delegate: CheckBox {
                        text: name
                        width: parent.width / 3
                        checked: paramShot[value]
                        onCheckedChanged: paramShot[value] = checked;
                    }
                }


            }
            Rectangle {
                implicitWidth: parent.width
                implicitHeight: 1
                color: "grey"
            }
            Grid{
                columns: 3
                width: parent.width
                Repeater {
                    model: pickProp
                    delegate: CheckBox {
                        text: name
                        width: parent.width / 3
                        checked: paramShot[value]
                        onCheckedChanged: paramShot[value] = checked;
                    }
                }
            }
            Rectangle {
                implicitWidth: parent.width
                implicitHeight: 1
                color: "grey"
            }
            Grid{
                columns: 3
                width: parent.width
                Repeater {
                    model: cutProp
                    delegate: CheckBox {
                        text: name
                        width: parent.width / 3
                        checked: paramShot[value]
                        onCheckedChanged: paramShot[value] = checked;
                    }
                }
            }
            Rectangle {
                implicitWidth: parent.width
                implicitHeight: 1
                color: "grey"
            }
            Grid{
                columns: 3
                width: parent.width
                Repeater {
                    model: postProp
                    delegate: CheckBox {
                        text: name
                        width: parent.width / 3
                        checked: paramShot[value]
                        onCheckedChanged: paramShot[value] = checked;
                    }
                }
            }
        }
    }

    ListModel{
        id: propModel
        ListElement { name: "Miss"; value:"isMiss"; type: "general"  }
        ListElement { name: "Shot"; value: "isShot"; type: "general" }
        ListElement { name: "Drive"; value: "isDrive"; type: "general" }
        ListElement { name: "Post"; value:"isPost"; type: "general" }
        ListElement { name: "Cut"; value: "isCut"; type: "general" }
        ListElement { name: "Contested"; value:"isContested"; type: "general"  }
        ListElement { name: "Offhand"; value:"isOffhand"; type: "general" }
        ListElement { name: "Mismatch"; value:"isMismatch"; type: "general" }
        ListElement { name: "Iso"; value:"isIso"; type: "general"}
        ListElement { name: "Faul"; value:"isFaul"; type:"general" }
        ListElement { name: "Transition"; value:"isTransition"; type:"general" }
        ListElement { name: "Dunk"; value:"isDunk"; type:"general" }
        ListElement { name: "Putback"; value:"isPutback"; type: "general" }
        ListElement { name: "SecondChance"; value:"isSecondChance"; type: "general" }
        ListElement { name: "OffTurnover"; value:"isOffTurnover"; type: "general" }
        ListElement { name: "Assisted"; value: "isAssisted"; type: "general" }
        ListElement { name: "Blocked"; value: "isBlocked"; type: "general" }
    }
    ListModel{
        id: shotProp
        ListElement { name: "Three Points"; value:"isThreePoints"; type: "shot" }
        ListElement { name: "OffTheDribble"; value:"isOffTheDribble"; type: "shot" }
        ListElement { name: "CatchAndShoot"; value:"isCatchAndShoot"; type: "shot" }
        ListElement { name: "Fadeaway"; value:"isFadeaway"; type: "shot" }
        ListElement { name: "Stepback"; value:"isStepback"; type: "shot" }
    }

    ListModel{
        id: pickProp
        ListElement { name: "PickAndRoll"; value:"isPickAndRoll"; type: "pick" }
        ListElement { name: "PickAndPop"; value:"isPickAndPop"; type: "pick" }
        ListElement{ name: "ScreenAssited"; value: "isScreenAssisted"; type: "pick" }
    }
    ListModel{
        id: cutProp
        ListElement { name: "Layup"; value:"isLayup"; type: "cut" }
        ListElement { name: "Floater"; value:"isFloater"; type: "cut" }
        ListElement { name: "Eurostep"; value:"isEurostep"; type: "cut" }
        ListElement { name: "Reverse"; value: "isReverse"; type: "cut" }
    }

    ListModel{
        id: postProp
        ListElement{ name: "Roll"; value: "isRoll"; type: "post" }
        ListElement{ name: "UpAndUnder"; value: "isUpAndUnder"; type: "post" }
        ListElement{ name: "Hookshot"; value: "isHookshot"; type: "post" }
        ListElement{ name: "Turnaround"; value: "isTurnaround"; type: "post" }
    }

}

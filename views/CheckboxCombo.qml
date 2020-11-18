import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQml.Models 2.15

Item{
    property var selected: []
    property string textVal: ""
    signal selectionChanged
    ComboBox {
        id: propertyCombobox
        anchors.fill: parent
        textRole: "text"
        model: propertyModel
        displayText: textVal
        delegate:
            CheckBox{
            text: model.name
            checked: model.on
            onCheckedChanged: {
                if(checked){
                    model.on = true;
                    if(!selected.includes(value))
                        selected.push(model.value);
                }
                else{
                    model.on = false;
                    var pos = selected.indexOf(value);
                    selected.splice(pos, 1);
                }
                selectionChanged();
                textVal = selected.toString();
            }
        }
        onCurrentIndexChanged: {
            currentIndex = 0;
        }
    }

    ListModel{
        id: propertyModel
        ListElement { name: "Two Points"; value:"!isThreePoints"; type: "shot"; on: false }
        ListElement { name: "Three Points"; value:"isThreePoints"; type: "shot"; on: false }
        ListElement { name: "Contested"; value:"isContested"; type: "general"; on: false }
        ListElement { name: "Uncontested"; value:"!isContested"; type: "general"; on: false }
        ListElement { name: "Offhand"; value:"isOffhand"; type: "general"; on: false }
        ListElement { name: "Post"; value:"isPost"; type: "general"; on: false }
        ListElement { name: "Mismatch"; value:"isMismatch"; type: "general"; on: false }
        ListElement { name: "Iso"; value:"isIso"; type: "general; on: fals"}
        ListElement { name: "Faul"; value:"isFaul"; type:"general"; on: false }
        ListElement { name: "Transition"; value:"isTransition"; type:"general"; on: false }
        ListElement { name: "Dunk"; value:"isDunk"; type:"general"; on: false }
        ListElement { name: "Putback"; value:"isPutback"; type: "general"; on: false }
        ListElement { name: "SecondChance"; value:"isSecondChance"; type: "general"; on: false }
        ListElement { name: "OffTurnover"; value:"isOffTurnover"; type: "general"; on: false }
        ListElement { name: "Drive"; value: "isDrive"; type: "general"; on: false }
        ListElement { name: "Cut"; value: "isCut"; type: "general" }
        ListElement { name: "ScreenAssited"; value: "isScreenAssisted"; type: "pick" }
        ListElement { name: "Assisted"; value: "isAssisted"; type: "general" }
        ListElement { name: "Blocked"; value: "isBlocked"; type: "general" }
        ListElement { name: "Shot"; value:"isShot"; type: "general"; on: false }
        ListElement { name: "OffTheDribble"; value:"isOffTheDribble"; type: "shot"; on: false }
        ListElement { name: "CatchAndShoot"; value:"isCatchAndShoot"; type: "shot"; on: false }
        ListElement { name: "Fadeaway"; value:"isFadeaway"; type: "shot"; on: false }
        ListElement { name: "Stepback"; value:"isStepback"; type: "shot"; on: false }
        ListElement { name: "PickAndRoll"; value:"isPickAndRoll"; type: "pick"; on: false }
        ListElement { name: "PickAndPop"; value:"isPickAndPop"; type: "pick"; on: false }
        ListElement { name: "Layup"; value:"isLayup"; type: "cut"; on: false }
        ListElement { name: "Floater"; value:"isFloater"; type: "cut"; on: false }
        ListElement { name: "Eurostep"; value:"isEurostep"; type: "cut"; on: false }
        ListElement { name: "Reverse"; value: "isReverse"; type: "cut"; on: false }
        ListElement { name: "Roll"; value: "isRoll"; type: "post"; on: false }
        ListElement { name: "UpAndUnder"; value: "isUpAndUnder"; type: "post"; on: false }
        ListElement { name: "Hookshot"; value: "isHookshot"; type: "post"; on: false }
        ListElement { name: "Turnaround"; value: "isTurnaround"; type: "post"; on: false }
    }
}

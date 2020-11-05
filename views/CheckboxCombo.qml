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
            onCheckedChanged: {
                if(checked)
                    selected.push(model.value);
                else{
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
        ListElement { name: "Two Points"; value:"!isThreePoints" }
        ListElement { name: "Three Points"; value:"isThreePoints" }
        ListElement { name: "Contested"; value:"isContested" }
        ListElement { name: "Uncontested"; value:"!isContested" }
        ListElement { name: "Offhand"; value:"isOffhand" }
        ListElement { name: "OffTheDribble"; value:"isOffTheDribble" }
        ListElement { name: "CatchAndShoot"; value:"isCatchAndShoot" }
        ListElement { name: "PickAndRoll"; value:"isPickAndRoll" }
        ListElement { name: "PickAndPop"; value:"isPickAndPop" }
        ListElement { name: "Post"; value:"isPost" }
        ListElement { name: "Mismatch"; value:"isMismatch" }
        ListElement { name: "Iso"; value:"isIso" }
        ListElement { name: "Layup"; value:"isLayup" }
        ListElement { name: "Faul"; value:"isFaul" }
        ListElement { name: "Transition"; value:"isTransition" }
        ListElement { name: "Clutch"; value:"isClutch" }
        ListElement { name: "Dunk"; value:"isDunk" }
        ListElement { name: "Floater"; value:"isFloater" }
        ListElement { name: "Eurostep"; value:"isEurostep" }
        ListElement { name: "Putback"; value:"isPutback" }
        ListElement { name: "SecondChance"; value:"isSecondChance" }
        ListElement { name: "OffTurnover"; value:"isOffTurnover" }
    }
}

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
        }
    }


    onAccepted: {
        console.log("Ok clicked");
        isMiss = isMissCheck.checkState;
        isContested = isContestedCheck.checkState;
        isThree = isThreeCheck.checkState;
    }
    onRejected: {
        console.log("Cancel clicked");
    }
}


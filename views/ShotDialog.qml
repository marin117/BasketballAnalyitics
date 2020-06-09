import QtQuick 2.0
import QtQuick.Controls 2.3

Dialog {
    id: shotDialog
    title: "Shot properties"
    standardButtons: Dialog.Ok | Dialog.Cancel
    modal: true
    property bool isMiss : false

    CheckBox {
        id: isMissCheck
        checked: false
        text: "Miss"
        tristate: false
    }

    onAccepted: {
        console.log("Ok clicked");
        isMiss = isMissCheck.checkState;
    }
    onRejected: {
        console.log("Cancel clicked");
    }
}


import QtQuick 2.0
import Shot 0.1
import QtQuick.Controls 2.3

Item {
    id: courtRoot
    objectName: "basketballCourtObject"
    signal shotAdded(int x, int y)
    signal canvasHeightChanged(int height, int prevHeight)
    signal canvasWidthChanged(int width, int prevWidth)

    // TODO: move this to seperate file
    Dialog {
        id: shotDialog
        title: "Shot properties"
        standardButtons: Dialog.Ok | Dialog.Cancel
        modal: true
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        CheckBox {
            id: isMiss
            checked: false
            text: "Miss"
            tristate: false
        }

        onAccepted: {
            console.log("Ok clicked");
            isMiss.checked = false;
            this.close();
        }
        onRejected: {
            console.log("Cancel clicked");
            isMiss.checked = false;
            this.close();
        }
    }

    Canvas {
        id: basketballCourtCanvas
        anchors.centerIn: parent
        anchors.fill: parent
        antialiasing: true
        transformOrigin: Item.TopLeft

        Image {
            id: basketballCourtImage
            anchors.centerIn:  parent
            z: -50
            antialiasing: true
            anchors.fill: parent
            source: "qrc:/res/res/halfcourt_4k.png"
            fillMode: Image.PreserveAspectFit
        }

        property var currWidth
        property var currHeight

        Component.onCompleted: {
            currWidth = width
            currHeight = height
        }

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset()
            ctx.strokeStyle = Qt.rgba(1,0,0,1);
            ctx.lineWidth = 1
            for(var i=0; i< mainModel.selectedShots.length; i++){
                ctx.ellipse(mainModel.selectedShots[i].x,  mainModel.selectedShots[i].y, 10, 10);
            }
            ctx.stroke()
        }
        MouseArea {
            property int it: 0
            id: canvasMouseArea
            anchors.centerIn: parent
            anchors.fill: parent
            onClicked: {
                shotDialog.open();
                shotDialog.accepted.connect(function(){
                    console.log(isMiss.checkState);
                    shotAdded(mouseX, mouseY);
                    basketballCourtCanvas.requestPaint();
                    it+=1;
                    console.log("Iterator " + it);
                });
            }
        }

        onWidthChanged: {
            canvasWidthChanged(width, currWidth);
            currWidth = width;
        }

        onHeightChanged: {
            canvasHeightChanged(height, currHeight);
            currHeight = height;
        }
    }

    function repaintCanvas(){
        basketballCourtCanvas.requestPaint();
    }

}




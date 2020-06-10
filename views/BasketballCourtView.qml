import QtQuick 2.0
import Shot 0.1
import QtQuick.Controls 2.3

Item {
    id: courtRoot
    objectName: "basketballCourtObject"
    signal shotAdded(Shot shot)
    signal canvasHeightChanged(int height, int prevHeight)
    signal canvasWidthChanged(int width, int prevWidth)

    Shot {
        id: newShot
        x: 0
        y: 0
        isMiss: false
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
            ctx.reset();
            ctx.lineWidth = 2;
            for(var i=0; i< mainModel.selectedShots.length; i++){
                ctx.beginPath();
                if(mainModel.selectedShots[i].isMiss === true)
                    ctx.strokeStyle = Qt.rgba(1,0,0,1);
                else
                    ctx.strokeStyle = Qt.rgba(0,0.7,0,1);
                ctx.ellipse(mainModel.selectedShots[i].x,  mainModel.selectedShots[i].y, 10, 10);
                ctx.stroke();
            }
        }
        MouseArea {
            id: canvasMouseArea
            anchors.centerIn: parent
            anchors.fill: parent
            onClicked: {
                shotDlgLoader.active = false;
                shotDlgLoader.active = true;
                shotDlgLoader.item.open();
                shotDlgLoader.item.accepted.connect(function(){
                    newShot.x = mouseX;
                    newShot.y = mouseY;
                    newShot.isMiss = shotDlgLoader.item.isMiss;
                    shotAdded(newShot);
                    basketballCourtCanvas.requestPaint();
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


    Loader{
        id: shotDlgLoader
        source: "ShotDialog.qml"
        active: false
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

    }
}




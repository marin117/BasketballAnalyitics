import QtQuick 2.0
import Shot 0.1

Item {
    objectName: "basketballCourtObject"
    signal shotAdded(int x, int y)
    signal canvasHeightChanged(int height, int prevHeight)
    signal canvasWidthChanged(int width, int prevWidth)

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
            source: "qrc:/res/res/basketball_court2.png"
            fillMode: Image.Stretch

        }

        property var prevWidth
        property var prevHeight
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
            id: canvasMouseArea

            anchors.centerIn: parent
            anchors.fill: parent
            onClicked: {
                shotAdded(mouseX, mouseY);
                basketballCourtCanvas.requestPaint();
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

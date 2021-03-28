import QtQuick 2.0
import Shot 0.1
import QtQuick.Controls 2.3
import Player 0.1

Item {
    id: courtRoot
    objectName: "basketballCourtObject"
    signal shotAdded(Shot shot)
    signal canvasHeightChanged(int height, int prevHeight)
    signal canvasWidthChanged(int width, int prevWidth)

    property int imageScaleX: 400
    property int imageScaleY: 300
    property bool enabled: true
    property int quarter: mainModel.selectedQuarter
    property bool isClutchSelected: false
    property var filters : []
    property var shots: mainModel.selectedPlayer.shots

    property var shot: Shot {}

    Component {
        id: shotDialogComp
        ShotDialog {
            id: shotDialog
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
            anchors.top: parent.top
            z: -50
            antialiasing: true
            anchors.fill: parent
            source: "qrc:/res/res/halfcourt_4k.png"
            fillMode: Image.Stretch
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
            if(mainModel.selectedPlayer !== null){
                for(var i=0; i< shots.length; i++){
                    var shouldDraw = true;
                    if(filters.length > 0){
                        for(var j=0; j < filters.length; j++){
                            if(shots[i][filters[j]] === false && shots[i][filters[j]] !== undefined)
                                shouldDraw = false;
                            // this is just temporary for special cases, need to rewrite if more special cases occures
                            if(filters[j] === '!isThreePoints' && shots[i]['isThreePoints'])
                                shouldDraw = false;
                            if(filters[j] === '!isContested' && shots[i]['isContested'])
                                shouldDraw = false;
                        }
                    }
                    if(shouldDraw)  drawShot(ctx, shots[i]);
                }
            }
        }
        MouseArea {
            id: canvasMouseArea
            anchors.centerIn: parent
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MiddleButton
            enabled: courtRoot.enabled
            onPressed:  {
                var x;
                var y;
                if(mainModel.selectedPlayer !== null){
                    shotDlgLoader.active = false;
                    shotDlgLoader.active = true;

                    if (canvasMouseArea.pressedButtons & Qt.RightButton) {
                        shotDlgLoader.item.shot.isMiss = true;
                    } else if (canvasMouseArea.pressedButtons & Qt.LeftButton) {
                        shotDlgLoader.item.shot.isMiss = false;
                    }
                    if(canvasMouseArea.pressedButtons & Qt.MiddleButton){
                        shotDlgLoader.item.shot.isThreePoints = true;
                    }
                    shotDlgLoader.item.open();

                    shotDlgLoader.item.accepted.connect(function(){
                        x = mouseX * imageScaleX / width;
                        y = mouseY * imageScaleY /height;
                        shotProperties(x, y);
                        //shotAdded(shot);
                        mainModel.onShotAdded(shot);
                        basketballCourtCanvas.requestPaint();
                    });
                }
            }
        }
    }

    function repaintCanvas(){
        basketballCourtCanvas.requestPaint();
    }

    function drawShot(ctx, shot, filter){
        ctx.beginPath();
        if(shot.isMiss === true){
            ctx.strokeStyle = Qt.rgba(1,0,0,1);
            ctx.fillStyle = Qt.rgba(1,0,0,1);
        }
        else{
            ctx.strokeStyle = Qt.rgba(0,0.7,0,1);
            ctx.fillStyle = Qt.rgba(0,0.7,0,1);
        }
        if(courtRoot.enabled || shot.quarter === quarter || quarter < 0){
            ctx.ellipse(shot.x * width/imageScaleX,  shot.y * height/imageScaleY, 10, 10);
            ctx.fill();
            ctx.stroke();
        }

    }

    Loader{
        id: shotDlgLoader
        sourceComponent: shotDialogComp
        active: true
//        x: parent.width  / 2
        y: parent.height / 2
    }

    function shotProperties(x, y) {

        shot = shotDlgLoader.item.shot;
        shot.x = x;
        shot.y = y;
        console.log(isClutchSelected);
        shot.isClutch = isClutchSelected;
    }
    onFiltersChanged: {
        console.log(filters);
        repaintCanvas();
    }
}




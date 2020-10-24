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
    property int quarter: 1
    property bool isClutchSelected: false
    property string filter : ""

    Shot {
        id: newShot
        x: 0
        y: 0
        isMiss: false
        isOffhand : false
        isOffTheDribble : false
        isCatchAndShoot : false
        isPickAndRoll : false
        isPickAndPop : false
        isPost : false
        isMismatch : false
        isIso : false
        isLayup : false
        isFaul : false
        isTransition : false
        isThreePoints: false
        isClutch: isClutchSelected
        isDunk: false
        isFloater: false
        isEurostep: false
        isPutback: false
        isSecondChance: false
        isOffTurnover: false
    }

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
                for(var i=0; i< mainModel.selectedShots.length; i++){
                    drawShot(ctx, mainModel.selectedShots[i]);
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
                if(mainModel.selectedPlayer !== null){
                    shotDlgLoader.active = false;
                    shotDlgLoader.active = true;

                    if (canvasMouseArea.pressedButtons & Qt.RightButton) {
                        shotDlgLoader.item.isMiss = true;
                    } else if (canvasMouseArea.pressedButtons & Qt.LeftButton) {
                        shotDlgLoader.item.isMiss = false;
                    }
                    if(canvasMouseArea.pressedButtons & Qt.MiddleButton){
                        shotDlgLoader.item.isThree = true;
                    }
                    shotDlgLoader.item.open();

                    shotDlgLoader.item.accepted.connect(function(){
                        newShot.x = mouseX * imageScaleX / width;
                        newShot.y = mouseY * imageScaleY /height;
                        shotProperties();
                        shotAdded(newShot);
                        basketballCourtCanvas.requestPaint();
                    });
                }
            }
        }
    }

    function repaintCanvas(){
        basketballCourtCanvas.requestPaint();
    }

    function drawShot(ctx, shot){
        ctx.beginPath();
        if(shot[filter] || filter === ""){
            if(shot.isMiss === true){
                ctx.strokeStyle = Qt.rgba(1,0,0,1);
                ctx.fillStyle = Qt.rgba(1,0,0,1);
            }
            else{
                ctx.strokeStyle = Qt.rgba(0,0.7,0,1);
                ctx.fillStyle = Qt.rgba(0,0.7,0,1);
            }
            if(courtRoot.enabled || shot.quarter === mainModel.selectedQuarter){
                ctx.ellipse(shot.x * width/imageScaleX,  shot.y * height/imageScaleY, 10, 10);
                ctx.fill();
                ctx.stroke();
            }
        }
    }

    Loader{
        id: shotDlgLoader
        sourceComponent: shotDialogComp
        active: true
        //x: (parent.width - width) / 2
        y: parent.height / 2

    }

    function shotProperties() {
        newShot.isMiss = shotDlgLoader.item.isMiss;
        newShot.isThreePoints = shotDlgLoader.item.isThree;
        newShot.isContested = shotDlgLoader.item.isContested;
        newShot.isOffhand = shotDlgLoader.item.isOffhand;
        newShot.isOffTheDribble = shotDlgLoader.item.isOffTheDribble;
        newShot.isCatchAndShoot = shotDlgLoader.item.isCatchAndShoot;
        newShot.isPickAndRoll = shotDlgLoader.item.isPickAndRoll;
        newShot.isPickAndPop = shotDlgLoader.item.isPickAndPop;
        newShot.isPost = shotDlgLoader.item.isPost;
        newShot.isMismatch = shotDlgLoader.item.isMismatch;
        newShot.isIso = shotDlgLoader.item.isIso;
        newShot.isLayup = shotDlgLoader.item.isLayup;
        newShot.isFaul = shotDlgLoader.item.isFaul;
        newShot.isTransition = shotDlgLoader.item.isTransition;
        newShot.isClutch = isClutchSelected;
        newShot.isDunk = shotDlgLoader.item.isDunk;
        newShot.isFloater = shotDlgLoader.item.isFloater;
        newShot.isEurostep = shotDlgLoader.item.isEurostep;
        newShot.isPutback = shotDlgLoader.item.isPutback;
        newShot.isSecondChance = shotDlgLoader.item.isSecondChance;
        newShot.isOffTurnover = shotDlgLoader.item.isOffTurnover;
    }
}




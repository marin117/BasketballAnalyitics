import QtQuick 2.0

Item {
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
            for(var i=0; i< canvasMouseArea.shots.length; i++){
                var point = canvasMouseArea.shots[i]
                ctx.ellipse(point['x'], point['y'], 10, 10)
            }
            ctx.stroke()
        }
        MouseArea {
            id: canvasMouseArea
            property var shots: []
            anchors.centerIn: parent
            anchors.fill: parent
            onClicked: {
                shots.push({'x': mouseX , 'y':mouseY })
                basketballCourtCanvas.requestPaint()
            }
        }

        onWidthChanged: {
            for(var i=0; i< canvasMouseArea.shots.length; i++){
                var point = canvasMouseArea.shots[i]
                canvasMouseArea.shots[i]['x'] = point['x'] * width/ currWidth
            }
            currWidth = width
        }

        onHeightChanged: {
            for(var i=0; i< canvasMouseArea.shots.length; i++){
                var point = canvasMouseArea.shots[i]
                canvasMouseArea.shots[i]['y'] = point['y'] * height / currHeight
            }

            currHeight = height
        }
    }
}

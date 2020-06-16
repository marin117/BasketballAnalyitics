#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/model/playerlistmodel.h"
#include <QQuickView>
#include <QQmlContext>
#include "mainmodel.h"
#include "model/player.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);



    MainModel mainModel;

    qmlRegisterType<PlayerListModel>("PlayerListModel", 0 ,1, "PlayerListModel");
    qmlRegisterType<Shot>("Shot", 0 ,1, "Shot");
    qmlRegisterType<Player>("Player", 0 ,1, "Player");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/views/main.qml"));
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("mainModel", &mainModel);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    qDebug() << engine.rootObjects().size();

    QObject* playerListObject = engine.rootObjects().first()->findChild<QObject*>("playerListObject");
    QObject* basketballCourtObject = engine.rootObjects().first()->findChild<QObject*>("basketballCourtObject");
    QObject* mainWindow = engine.rootObjects().first();

    QObject::connect(playerListObject, SIGNAL(selectedPlayerChanged(int)), &mainModel, SLOT(onSelectedPlayerChanged(int)));
    QObject::connect(basketballCourtObject, SIGNAL(shotAdded(Shot*)), &mainModel, SLOT(onShotAdded(Shot*)));
    QObject::connect(basketballCourtObject, SIGNAL(canvasWidthChanged(int, int)), &mainModel, SLOT(onWidthChanged(int, int)));
    QObject::connect(basketballCourtObject, SIGNAL(canvasHeightChanged(int, int)), &mainModel, SLOT(onHeightChanged(int, int)));
    QObject::connect(mainWindow, SIGNAL(selectedTeamChanged(int)), &mainModel, SLOT(onSelectedTeamChanged(int)));

    return app.exec();
}

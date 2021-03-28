#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/model/playerlistmodel.h"
#include <QQuickView>
#include <QQmlContext>
#include "mainmodel.h"
#include "model/player.h"
#include "model/statistics.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    MainModel mainModel;

    qmlRegisterType<PlayerListModel>("PlayerListModel", 0 ,1, "PlayerListModel");
    qmlRegisterType<Shot>("Shot", 0 ,1, "Shot");
    qmlRegisterType<Player>("Player", 0 ,1, "Player");
    qmlRegisterType<Statistics>("Statistics", 0, 1, "Statistics");
    qmlRegisterType<Team>("Team", 0, 1, "Team");

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

    return app.exec();
}

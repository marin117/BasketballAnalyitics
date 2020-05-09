#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/model/playertablemodel.h"
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    PlayerTableModel playerModel;

    QList<Player> playerList;
    playerList.append(Player("Ivo", "Ivic", 15));
    playerList.append(Player("Marko", "Markic", 11));
    playerList.append(Player("Jure", "Juric", 13));
    playerList.append(Player("Fran", "Jovic", 12));

    playerModel.setPlayerList(playerList);

    qmlRegisterType<PlayerTableModel>("PlayerTableModel", 0 ,1, "PlayerTableModel");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/views/main.qml"));
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("playerModel", &playerModel);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/model/playertablemodel.h"
#include <QQuickView>
#include <QQmlContext>
#include "mainmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    //playerModel.setPlayerList(playerList);

    MainModel mainModel;

    //qmlRegisterType<PlayerTableModel>("PlayerTableModel", 0 ,1, "PlayerTableModel");

    qmlRegisterType<PlayerTableModel>("MainModel", 0 ,1, "MainModel");

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
    QObject::connect(playerListObject, SIGNAL(selectedPlayerChanged(int)), &mainModel, SLOT(onSelectedPlayerChanged(int)));

    return app.exec();
}

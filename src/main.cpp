#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>
#include <QTimer>

int main(int argc, char* argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QCommandLineParser parser;

    QCommandLineOption autoExit(QStringList() << "x" << "auto-exit",
                                QCoreApplication::translate("main", "Gracefully exits after 0.2s"));
    parser.addOption(autoExit);
    parser.addHelpOption();
    parser.process(app);

    if (parser.isSet(autoExit)) {
        QTimer::singleShot(200, &app, &QGuiApplication::quit);
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* obj, const QUrl& objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

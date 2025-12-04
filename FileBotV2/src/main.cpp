#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QString qmlPath = QDir::cleanPath(
        QCoreApplication::applicationDirPath() + "/../qml/Main.qml"
    );

    engine.load(QUrl::fromLocalFile(qmlPath));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
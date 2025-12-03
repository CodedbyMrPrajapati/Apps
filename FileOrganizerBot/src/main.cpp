#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("FilterGlass");
    QFile file("../styles/main.qss");
    if (file.open(QFile::ReadOnly)){
        QString style = QLatin1String(file.readAll());
        app.setStyleSheet(style);
    } else {
        throw std::invalid_argument("Error Loading StyleSheet");
    }
    MainWindow window;
    window.show();
    return app.exec();
}

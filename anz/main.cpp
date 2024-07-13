#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    // Example of updating values
    w.setPercentage("75%");
    w.setTemperature("30");
    w.setHumidity("80");

    return a.exec();
}

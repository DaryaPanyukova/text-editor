#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.resize(800, 600);
    mainWindow.setWindowTitle("Notepad");
    mainWindow.show();
    return app.exec();
}

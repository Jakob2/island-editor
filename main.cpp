#include "mainwindow.h"
#include <QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;
    World world;
    Db db;
    Gui gui;
    gui.setupUi(w);
    w->show();
    gui.connectGui();
    gui.zoom();
    gui.fillInNames();

    return a.exec();
}

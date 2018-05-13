#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TemperatureModel model;
    Controller controller(&model);
    MainWindow w(&controller, &model);
    model.addObserver(&w);

    w.show();

    return a.exec();
}

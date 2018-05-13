#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include <QLabel>
#include "temperaturemodel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT
private:
    Controller* controller;
    QString celsius_temp_prefix;
    QString farenheit_temp_prefix;
    QLabel temp_widget;
    TemperatureModel* temp_model;
public:
    explicit MainWindow(Controller* controller, TemperatureModel* model, QWidget *parent = 0);
    void update() override;
    ~MainWindow();
public slots:
    void updateButtonClicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

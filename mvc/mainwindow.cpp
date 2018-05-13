#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller* controller, TemperatureModel* model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), controller(controller), temp_model(model)
{
    ui->setupUi(this);

    this->celsius_temp_prefix = "Celsius T: ";
    this->farenheit_temp_prefix = "Farenheit T: ";
    this->ui->tempLabel->setText(celsius_temp_prefix + farenheit_temp_prefix);
    connect(this->ui->updateButton, SIGNAL(clicked(bool)), this, SLOT(updateButtonClicked()));
}

void MainWindow::updateButtonClicked(){
    QString temp = this->ui->tempEdit->text();
    this->ui->tempEdit->clear();
    this->controller->validateAndSetData(temp);
}

void MainWindow::update(){
    this->ui->tempLabel->setText(celsius_temp_prefix + QString::number(temp_model->getCelsiusTemp())
                                 + '\n'
                                 + farenheit_temp_prefix + QString::number(temp_model->getFarenheitTemp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

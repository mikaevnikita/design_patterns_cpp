#include "controller.h"

Controller::Controller(TemperatureModel* model)
    :model(model)
{}
void Controller::validateAndSetData(QString new_temperature){
    bool valid;
    double temperature = new_temperature.toDouble(&valid);
    if(valid)
        model->setCelsiusTemp(temperature);
}

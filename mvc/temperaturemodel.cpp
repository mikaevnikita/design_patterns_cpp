
#include "temperaturemodel.h"

TemperatureModel::TemperatureModel(double celsius_temp)
    :celsius_temp(celsius_temp)
{
}

void TemperatureModel::setCelsiusTemp(double celsius_temp){
    this->celsius_temp = celsius_temp;
    notify();
}

double TemperatureModel::getCelsiusTemp() const{
    return celsius_temp;
}


void TemperatureModel::setFarenheitTemp(double farenheit_temp){
    celsius_temp = (farenheit_temp - 32) / 1.8;
    notify();
}

double TemperatureModel::getFarenheitTemp() const{
    return celsius_temp * 1.8 + 32;
}

#ifndef TEMPERATUREMODEL_H
#define TEMPERATUREMODEL_H

#include "observable.h"

class TemperatureModel: public Observable{
private:
    double celsius_temp;
public:
    TemperatureModel(double celsius_temp = 0);
    void setCelsiusTemp(double celsius_temp);
    double getCelsiusTemp() const;
    void setFarenheitTemp(double farenheit_temp);
    double getFarenheitTemp() const;
};

#endif // TEMPERATUREMODEL_H

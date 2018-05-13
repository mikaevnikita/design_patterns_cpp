#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "temperaturemodel.h"
#include <QString>

class Controller
{
private:
    TemperatureModel* model;
public:
    Controller(TemperatureModel* model);
    void validateAndSetData(QString new_temperature);
};

#endif // CONTROLLER_H

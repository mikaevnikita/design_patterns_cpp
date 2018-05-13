#include "temperatureview.h"

TemperatureView::TemperatureView(TemperatureModel* model, QString prefix)
    :model(model), prefix(prefix)
{}

void TemperatureView::update(){
    this->setText(prefix + QString(model->getCelsiusTemp()));
}

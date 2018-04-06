#include <iostream>
using namespace std;

/*
Паттерн Адаптер
+Выполняет преобразование между несовместимыми интерфейсами
*/

class FahrenheitSensor
{
private:
    float temp;
public:
    void setTemperature(float temp){
        this->temp = temp;
    }
    float getTemperature() {
      return this->temp;
    }
};

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual void setTemperature(float temp) = 0;
    virtual float getTemperature() = 0;
};

class Adapter : public Sensor
{
private:
  FahrenheitSensor* p_fsensor;
public:
    Adapter(FahrenheitSensor* p)
        : p_fsensor(p) {}
    void setTemperature(float temp){
        p_fsensor->setTemperature(temp*9.0 / 5.0 + 32.0);
    }
    float getTemperature() {
      return (p_fsensor->getTemperature()-32.0)*5.0/9.0;
    }
    ~Adapter() {
      delete p_fsensor;
    }
};

int main()
{
    FahrenheitSensor* fahrenheitSensor = new FahrenheitSensor;
    fahrenheitSensor->setTemperature(32);

    Sensor* p = new Adapter(fahrenheitSensor);
    cout << "Celsius temperature = " << p->getTemperature() << endl;
    p->setTemperature(0);
    cout << "Fahrenheir temperature = " << fahrenheitSensor->getTemperature() << endl;
    delete p;
    return 0;
}

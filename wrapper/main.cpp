#include <iostream>
#include <string>
using namespace std;

class Beverage{
protected:
    string description = "Unknown Description";
public:
    virtual string getDescription(){
        return description;
    }
    virtual double cost() = 0;
    virtual ~Beverage() = 0;
};

Beverage::~Beverage(){

}

class Espresso: public Beverage{
public:
    Espresso(){
        description = "Espresso";
    }
    double cost(){
        return 1;
    }
    ~Espresso(){
        cout << "eating espresso" << endl;
    }
};

class CondimentDecorator: public Beverage{
protected:
    Beverage* beverage;
public:
    virtual string getDescription() = 0;
    virtual ~CondimentDecorator(){
        delete beverage;
    }
};

class Milk: public CondimentDecorator{
public:
    Milk(Beverage* beverage){
        this->beverage = beverage;
    }
    string getDescription(){
        return beverage->getDescription() + ", Milk";
    }
    double cost(){
        return beverage->cost() + 0.99;
    }
    ~Milk(){
        cout << "eated milk" << endl;
    }
};

class Chocolate: public CondimentDecorator{
public:
    Chocolate(Beverage* beverage){
        this->beverage = beverage;
    }
    string getDescription(){
        return beverage->getDescription() + ", Chocolate";
    }
    double cost(){
        return beverage->cost() + 1.05;
    }
    ~Chocolate(){
        cout << "eated chocolate" << endl;
    }
};


int main()
{
    Beverage* chocolate_milk_espresso = new Espresso;
    chocolate_milk_espresso = new Milk(chocolate_milk_espresso);
    chocolate_milk_espresso = new Chocolate(chocolate_milk_espresso);
    cout << chocolate_milk_espresso->getDescription() <<
            " for " << chocolate_milk_espresso->cost() << endl;
    delete chocolate_milk_espresso;
    return 0;
}

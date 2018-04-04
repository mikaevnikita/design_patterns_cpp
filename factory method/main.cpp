#include <iostream>
#include <string>
using namespace std;

/*
Паттерн фабричный метод.
+Программируем на уровне интерфейса а не реализации
+Зависимости от абстрактных классов / интерфейсов а не от конкретных классов

Используется когда надо создавать объекты одного конкретного типа
*/


class Pizza{
public:
    virtual string getDescription() = 0;
    void cut(){
        //нарезаем пиццу
    }
    void pack(){
        //упаковываем пиццу
    }
};

class ChicagoPepperoniPizza: public Pizza{
public:
    string getDescription(){
        return "Chicago Pepperoni Pizza";
    }
};

class ChicagoMargaritaPizza: public Pizza{
public:
    string getDescription(){
        return "Chicago Margarita Pizza";
    }
};

class NYPepperoniPizza: public Pizza{
public:
    string getDescription(){
        return "NY Pepperoni Pizza";
    }
};

class NYMargaritaPizza: public Pizza{
public:
    string getDescription(){
        return "NY Margarita Pizza";
    }
};


class PizzaStore{
protected:
    virtual Pizza* createPizza(const string &pizza_type) = 0;
public:
    Pizza* orderPizza(const string& pizza_type){
        Pizza* pizza = createPizza(pizza_type);
        pizza->cut();
        pizza->pack();
        return pizza;
    }
};

class NYPizzaStore: public PizzaStore{
protected:
    Pizza* createPizza(const string &pizza_type){
        if(pizza_type == "Margarita")
            return new NYMargaritaPizza;
        else if(pizza_type == "Pepperoni")
            return new NYPepperoniPizza;
    }
};

class ChicagoPizzaStore: public PizzaStore{
protected:
    Pizza* createPizza(const string &pizza_type){
        if(pizza_type == "Margarita")
            return new ChicagoMargaritaPizza;
        else if(pizza_type == "Pepperoni")
            return new ChicagoPepperoniPizza;
    }
};


int main()
{
    PizzaStore* pizzaStore = new ChicagoPizzaStore;

    Pizza* pizza = pizzaStore->orderPizza("Margarita");
    cout << pizza->getDescription() << endl;
    delete pizza;

    pizza = pizzaStore->orderPizza("Pepperoni");
    cout << pizza->getDescription() << endl;
    delete pizza;


    delete pizzaStore;
    pizzaStore = new NYPizzaStore;

    pizza = pizzaStore->orderPizza("Margarita");
    cout << pizza->getDescription() << endl;
    delete pizza;

    pizza = pizzaStore->orderPizza("Pepperoni");
    cout << pizza->getDescription() << endl;
    delete pizza;

    delete pizzaStore;

    return 0;
}

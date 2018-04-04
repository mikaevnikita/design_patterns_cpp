#include <iostream>
#include <string>
using namespace std;

/*
Паттерн абстрактная фабрика.
+Изменение фабрики в рантайме
+Программируем на уровне интерфейса а не реализации
+Зависимости от абстрактных классов / интерфейсов а не от конкретных классов

Используется когда нужно создавать группы объектов
В данном случае реализована обычная фабрика, но в абстрактной создается группа объектов.
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



class PizzaFactory{
public:
    virtual Pizza* createPizza(const string& pizza_type) = 0;
};

class NYPizzaFactory: public PizzaFactory{
public:
    Pizza* createPizza(const string &pizza_type){
        if(pizza_type == "Margarita")
            return new NYMargaritaPizza;
        else if(pizza_type == "Pepperoni")
            return new NYPepperoniPizza;
    }
};

class ChicagoPizzaFactory: public PizzaFactory{
public:
    Pizza* createPizza(const string &pizza_type){
        if(pizza_type == "Margarita")
            return new ChicagoMargaritaPizza;
        else if(pizza_type == "Pepperoni")
            return new ChicagoPepperoniPizza;
    }
};

class PizzaStore{
private:
    PizzaFactory* pizzaFactory;
public:
    void setPizzaFactory(PizzaFactory* pizzaFactory){
        this->pizzaFactory = pizzaFactory;
    }
    Pizza* orderPizza(const string& pizza_type){
        Pizza* pizza = pizzaFactory->createPizza(pizza_type);
        pizza->cut();
        pizza->pack();
        return pizza;
    }
};

int main()
{
    PizzaFactory* pizzaFactory = new ChicagoPizzaFactory;

    PizzaStore pizzaStore;

    pizzaStore.setPizzaFactory(pizzaFactory);

    Pizza* pizza = pizzaStore.orderPizza("Margarita");
    cout << pizza->getDescription() << endl;
    delete pizza;

    pizza = pizzaStore.orderPizza("Pepperoni");
    cout << pizza->getDescription() << endl;
    delete pizza;


    delete pizzaFactory;
    pizzaFactory = new NYPizzaFactory;
    pizzaStore.setPizzaFactory(pizzaFactory);

    pizza = pizzaStore.orderPizza("Margarita");
    cout << pizza->getDescription() << endl;
    delete pizza;

    pizza = pizzaStore.orderPizza("Pepperoni");
    cout << pizza->getDescription() << endl;
    delete pizza;

    delete pizzaFactory;

    return 0;
}

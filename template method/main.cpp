#include <iostream>
using namespace std;

/*
Паттерн Шаблонный метод (Template Method)
определяет основной ход алгоритма, оставляя реализацию некоторых конкретных методов
классам-наследникам.
*/

class CaffeineBeverage{
public:
    void prepareRecipe(){
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    void boilWater(){
        //Вскипятить воду
        cout << "Boiling water.." << endl;
    }

    void pourInCup(){
        //Налить в чашку
        cout << "Pour in cup" << endl;
    }

    virtual void brew() = 0; //Заварить
    virtual void addCondiments() = 0;//Добавить ингридиенты
};

class Coffee: public CaffeineBeverage{
public:
    void brew(){
        cout << "Dripping cofee" << endl;
    }
    void addCondiments(){
        cout << "adding sugar and milk" << endl;
    }
};

class Tea: public CaffeineBeverage{
public:
    void brew(){
        cout << "Stepping the tea" << endl;
    }

    void addCondiments(){
        cout << "Adding lemon" << endl;
    }
};

int main()
{
    CaffeineBeverage* caffeine_beverage = new Coffee;
    caffeine_beverage->prepareRecipe();
    delete caffeine_beverage;
    cout << "---" << endl;
    caffeine_beverage = new Tea;
    caffeine_beverage->prepareRecipe();
    delete caffeine_beverage;
    return 0;
}

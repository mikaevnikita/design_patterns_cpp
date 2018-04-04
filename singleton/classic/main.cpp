#include <iostream>
#include <string>
using namespace std;

/*
Классическая реализация паттерна одиночка (синглтон)
+Отложенная инициализация (lazy initialization)
-В многопоточной среде возникнут проблемы
-Об удалении объекта должны позаботиться во внешней среде
*/

class Singleton{
private:
    static Singleton* p_singleton;
    Singleton(){};
    Singleton(const Singleton&){};
public:
    static Singleton* getInstance(){
        if(!p_singleton)
            p_singleton = new Singleton;
        return p_singleton;
    }
};

Singleton* Singleton::p_singleton = nullptr;

int main()
{
    Singleton* p_singleton = Singleton::getInstance();
    return 0;
}

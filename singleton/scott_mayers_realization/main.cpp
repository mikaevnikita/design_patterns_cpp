#include <iostream>
#include <string>
using namespace std;

/*
Реализация паттерна одиночка (синглтон) предложенная Скоттом Майерсом
+Отложенная инициализация (lazy initialization)
-В многопоточной среде возникнут проблемы
*/

class Singleton{
private:
    Singleton(){};
    Singleton(const Singleton&){};
public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
};


int main()
{
    Singleton& singleton = Singleton::getInstance();
    return 0;
}

#include <iostream>
#include <string>
#include <mutex>
using namespace std;

/*
Потокобезопасная реализация паттерна синглтон
-об удалении объекта необходимо заботиться
*/

class Singleton{
private:
    static Singleton* p_singleton;
    Singleton(){};
    Singleton(const Singleton&){};
public:
    static Singleton* getInstance(){
        if(!p_singleton){
            std::mutex sync;
            sync.lock();
            if(!p_singleton)
                p_singleton = new Singleton;
            sync.unlock();
        }
        return p_singleton;
    }
};

Singleton* Singleton::p_singleton = nullptr;

int main()
{
    Singleton* p_singleton = Singleton::getInstance();
    return 0;
}

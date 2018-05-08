#include <iostream>
using namespace std;

/*
Паттерн Заместитель (Proxy)
Имеет множество разновидностей: удаленный заместитель, виртуальный заместитель, заместитель - защитник
, заместитель - логгер, так же может использоваться для доп логики перед вызовом метода и после.
В данном примере демонстрируется использование паттерна для отложенной инициализации (lazy initialization)
Адаптер - предоставляет другой интерфейс
Декоратор - расширяет поведение через один и тот же интерфейс
Заместитель - предоставляет тот же интерфейс
*/


class Image{
public:
    virtual void show() = 0;
};

class NetworkImage: public Image{
    //Very hard initialization object
public:
    void show() override{
        cout << "Show: Loaded image from Internet" << endl;
    }
};

class ProxyImage: public Image{
private:
    NetworkImage* image;
    void loadImage(){
        if(image == nullptr)
            image = new NetworkImage;//lazy initialization
    }
public:
    ProxyImage()
        :image(nullptr)
    {}
    void show() override{
        if(image != nullptr)
            image->show();
        else{
            cout << "Show: Image loading.." << endl;
            loadImage();
        }
    }
    ~ProxyImage(){
        delete image;
    }
};

int main()
{
    Image* image = new ProxyImage;
    image->show();
    //wait many seconds..
    image->show();
    return 0;
}

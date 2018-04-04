#include <iostream>
#include <string>
using namespace std;

/*
Паттерн абстрактная фабрика.
+Создает группы родственных объектов
+Программируем на уровне интерфейса а не реализации
+Зависимости от абстрактных классов / интерфейсов а не от конкретных классов
*/

class Button{
public:
    virtual void show() = 0;
};

class WinButton: public Button{
public:
    void show(){
        cout << "Win button" << endl;
    }
};

class MacButton: public Button{
public:
    void show(){
        cout << "Mac button" << endl;
    }
};

class Checkbox{
public:
    virtual void show() = 0;
};

class MacCheckbox: public Checkbox{
public:
    void show(){
        cout << "Mac checkbox" << endl;
    }
};

class WinCheckbox: public Checkbox{
public:
    void show(){
        cout << "Win checkbox" << endl;
    }
};

class GUIFactory{
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};

class WinFactory: public GUIFactory{
public:
    Button* createButton(){
        return new WinButton;
    }
    Checkbox* createCheckbox(){
        return new WinCheckbox;
    }
};

class MacFactory: public GUIFactory{
public:
    Button* createButton(){
        return new MacButton;
    }
    Checkbox* createCheckbox(){
        return new MacCheckbox;
    }
};

class Application{
    GUIFactory* guiFactory;
    Button* button;
    Checkbox* checkbox;
public:
    Application(const string& os){
        if(os == "Mac")
            guiFactory = new MacFactory;
        else if(os == "Win")
            guiFactory = new WinFactory;
        button = guiFactory->createButton();
        checkbox = guiFactory->createCheckbox();
    }
    void show(){
        button->show();
        checkbox->show();
    }
    ~Application(){
        delete guiFactory;
    }
};


int main()
{
    Application app("Mac");
    app.show();
    return 0;
}

#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

/*
 * Паттерн Прототип (Prototype)
 * +позволяет копировать объекты любой сложности без привязки к их конкретным классам за счет
 * делегирования копирования самим классам
 * +пример репозитория объектов
 *
+если создание объектов для клиента является нетривиальной задачей, например, когда объект составной;
избежать множества фабрик для создания конкретных экземпляров классов;
если клиент не знает специфики создания объекта.

*/

class Shape {
private:
    int x;
    int y;
    string color;
public:
    Shape() {
    }

    Shape(int x, int y, string color)
        :x(x), y(y), color(color)
    {}

    Shape(const Shape& target) {
        x = target.x;
        y = target.y;
        color = target.color;
    }

    virtual Shape* clone() = 0;

    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

    string getColor() const{
        return color;
    }

    void setX(int x){
        this->x = x;
    }

    void setY(int y){
        this->y = y;
    }

    void setColor(const string& color){
        this->color = color;
    }

    bool operator==(Shape* shape2) {
        if(shape2 == nullptr)
            return false;
        return shape2->x == x and shape2->y == y and shape2->color == color;
    }

    virtual void showShape() const{
        cout << "X: " << x << " Y: " << y << " Color: " << color;
    }
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle()
        :Shape(){
    }

    Circle(int x, int y, string color, int radius)
        :Shape(x, y, color), radius(radius)
    {}

    Circle(const Circle& target)
        :Shape(target)
    {
        radius = target.radius;
    }

    Shape* clone() override {
        return new Circle(*this);
    }

    void setRadius(int radius){
        this->radius = radius;
    }

    int getRadius() const{
        return radius;
    }

    bool operator==(Shape* object2) {
        Circle* shape2 = dynamic_cast<Circle*>(object2);
        if(!shape2)
            return false;
        return shape2->radius == radius;
    }

    virtual void showShape() const override{
        Shape::showShape();
        cout << " Radius: " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    int width;
    int height;
public:
    Rectangle()
        :Shape(){
    }

    Rectangle(int x, int y, string color, int width, int height)
        :Shape(x, y, color), width(width), height(height)
    {}

    Rectangle(const Rectangle& target)
        :Shape(target)
    {
        width = target.width;
        height = target.height;
    }

    Shape* clone() override {
        return new Rectangle(*this);
    }

    void setWidth(int width){
        this->width = width;
    }

    void setHeight(int height){
        this->height = height;
    }

    int getWidth() const{
        return width;
    }

    int getHeight() const{
        return height;
    }

    bool operator==(Shape* object2) {
        Rectangle* shape2 = dynamic_cast<Rectangle*>(object2);
        if(!shape2)
            return false;
        return shape2->width == width and shape2->height == height;
    }

    virtual void showShape() const override{
        Shape::showShape();
        cout << " Width: " << width << " Height: " << height << endl;
    }
};

//registry
class BundledShapeCache {
private:
    unordered_map<string, Shape*> cache;
public:
    void put(string key, Shape* shape) {
        cache[key] = shape;
    }

    Shape* get(const string& key) {
        auto iter = cache.find(key);
        if(iter == cache.end())
            return nullptr;
        return (*iter).second->clone();
    }

    ~BundledShapeCache(){
        for(auto it = cache.begin(); it != cache.end(); ++it){
            auto cache_pair = *it;
            delete cache_pair.second;
        }
    }
};

int main(){
    BundledShapeCache registry;

    Circle* circle = new Circle(5, 7, "Green", 45);
    Rectangle* rectangle = new Rectangle(6, 9, "Blue", 8, 10);

    circle->showShape();
    rectangle->showShape();

    registry.put("Big green circle", new Circle(5, 7, "Green", 45));
    registry.put("Medium blue rectangle", new Rectangle(6, 9, "Blue", 8, 10));

    Shape* circle_copy = registry.get("Big green circle");
    Shape* rectangle_copy = registry.get("Medium blue rectangle");

    circle_copy->showShape();
    rectangle_copy->showShape();
    return 0;
}

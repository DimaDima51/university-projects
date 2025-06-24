#include <iostream>
#include <memory>
using namespace std;

// Базовый класс
class Shape {
    public:
        virtual void draw() const = 0;
        virtual ~Shape() = default;
};

class Circle : public Shape {
    public:
        void draw() const override {
            cout << "draw() Circle" << endl;
        }
};

class Square : public Shape {
    public:
        void draw() const override {
            cout << "draw() Square" << endl;
        }
};

// Фабрика
class ShapeFactory {
    public:
        static unique_ptr<Shape> createShape(const string& type) {
            if (type == "circle")
                return make_unique<Circle>();
            else if (type == "square")
                return make_unique<Square>();
            else
                return nullptr;
        }
};

int main() {
    unique_ptr<Shape> s1 = ShapeFactory::createShape("circle");
    unique_ptr<Shape> s2 = ShapeFactory::createShape("square");

    s1->draw();
    s2->draw();

    return 0;
}

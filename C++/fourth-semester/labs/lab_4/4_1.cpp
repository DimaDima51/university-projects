#include <iostream>
using namespace std;

class Shape {
    public:
        // Чисто виртуальный метод
        virtual double getArea() const = 0;
        
        virtual ~Shape() {}
};

// Производный класс Circle
class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}

        double getArea() const {
            return 3.14159 * radius * radius;
        }
};

class Triangle : public Shape {
    private:
        double base;
        double height;
    public:
        Triangle(double b, double h) : base(b), height(h) {}

        double getArea() const {
            return (base * height) / 2.0;
        }
};

class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}

        double getArea() const {
            return width * height;
        }
};

void Compare(Shape& s1, Shape& s2) {
    double area1 = s1.getArea();
    double area2 = s2.getArea();

    if (area1 > area2) {
        cout << "Первый объект имеет большую площадь: " << area1 << " > " << area2 << '\n';
    } else if (area1 < area2) {
        cout << "Второй объект имеет большую площадь: " << area1 << " < " << area2 << '\n';
    } else {
        cout << "Объекты имеют равную площадь: " << area1 << '\n';
    }
}

int main() {

    Circle circle(5);
    Triangle triangle(3, 4);
    Rectangle rectangle(3, 4);

    cout << "Площадь круга: " << circle.getArea() << '\n';
    cout << "Площадь треугольника: " << triangle.getArea() << '\n';
    cout << "Площадь прямоугольника: " << rectangle.getArea() << '\n';
    
    Compare(circle, triangle);
    Compare(rectangle, triangle);

    return 0;
}
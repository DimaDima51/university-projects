#include <iostream>

class A {
    int& ptr;
    public:
        // Конструктор
        A(int& value) : ptr(value) {

        }

        // Конструктор копирования
        A(const A& other) : ptr(other.ptr) {
            std::cout << "Конструктор копирования" << '\n';
        } 

        // Оператор присваивания
        A& operator=(const A& other) {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
            std::cout << "Конструктор присваивания" << '\n';
        }

        void get_ptr() {
            std::cout << ptr << '\n';
        }
};

int main() {
    int value = 5;
    A obj1(value);
    std::cout << "value = " << value << '\n'; 
    std::cout << "obj1.ptr = ";
    obj1.get_ptr();

    value = 10;
    std::cout << "obj1.ptr = ";
    obj1.get_ptr();

    A obj2 = obj1;
    std::cout << "value = " << value << '\n';
    std::cout << "obj1.ptr = ";
    obj1.get_ptr();

    std::cout << "obj2.ptr = ";
    obj2.get_ptr();

    value = 25;
    A obj3(obj1);
    std::cout << "value = " << value << '\n';
    std::cout << "obj1.ptr = ";
    obj1.get_ptr();
    std::cout << "obj2.ptr = ";
    obj2.get_ptr();
    std::cout << "obj3.ptr = ";
    obj3.get_ptr();

    return 0;
}
#include <iostream>

class Base {
    public:
        // Виртуальная функция, возвращает указатель на Base
        virtual Base* getPtr() {
            Base *ptr;
            return ptr;
        }

        void print() {
            std::cout << "Base print" << '\n';
        }
};

// Наследник Base
class D: public Base {
    public:

        // Переопределение getPtr
        D* getPtr() {
            D* ptr;
            return ptr;
        }

        void print() {
            std::cout << "D print" << '\n';
        }
};


int main() {
    D obj; // Объект класса D
    Base* ptr = &obj; // Указатель на базовый класс, указывающий на объект D

    // Вызов методов черех объект D
    std::cout << obj.getPtr() << '\n';
    obj.print(); // D print

    // Вызов методов через указатель на базовый класс
    std::cout << ptr->getPtr() << '\n';
    ptr->print(); // Base print

    return 0;
}
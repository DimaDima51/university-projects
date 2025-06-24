#include <iostream>

class Base {
    double *x; // Указатель на динамически выделенный массив

    public:
        Base(int par1) {
            std::cout << "Base Constr" << '\n';
            x = new double[par1]; // Выделение памяти
        }

        virtual ~Base() {
            std::cout << "Base Destr" << '\n';
            delete[] x; // Освобождение памяти
        }
};

// Производный класс, наследник базового
class Derived: public Base {
    public:
        // Конструктор для производного класса
        Derived(int par1): Base(par1) { // Вызывается конструктор базового класса
            std::cout << "Derived Constr" << '\n';
        }

        // Деструктор для производного класса
        ~Derived() { // Деструктор
            std::cout << "Derived Destr" << '\n';
        }
};

int main() {
    // Указатель на базовый, но выделяем память под произвольный
    Base* ptr = new Derived(5);

    // Удаляем объект через указатель на базовый класс
    delete ptr;

    return 0;
}
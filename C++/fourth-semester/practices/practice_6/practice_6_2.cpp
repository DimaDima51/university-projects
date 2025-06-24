#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
    public:
        // Виртуальная функция
        virtual void print() {
            std::cout << "Base print" << '\n';
        }

        // Виртуальный деструктор
        // Нужен для удаления производных классов
        virtual ~Base() {
            std::cout << "Base Destr" << '\n';
        }
};

// Производный класс 1, наследник базового
class Derived1 : public Base {
    public:
        void print() {
            std::cout << "Derived1 print" << '\n';
        }

        ~Derived1() {
            std::cout << "Derived1 Destr" << '\n';
        }
};

// Производный класс 2, наследник производного класса 1
class Derived2 : public Derived1 {
    public:
        void print() {
            std::cout << "Derived2 print" << '\n';
        }

        ~Derived2() {
            std::cout << "Derived2 Destr" << '\n';
        }
};

Base* GetPObj() {
    int random = rand() % 3;
    Base* ptr;
    if (random == 0) {
        std::cout << "Base()" << '\n';
        return new Base();
    }
    else if (random == 1) {
        std::cout << "Derived1()" << '\n';
        return new Derived1();
    }
    else {
        std::cout << "Derived2()" << '\n';
        return new Derived2();
    }
}

int main() {
    srand(time(0));

    Base* pb;
    for (int i = 0; i < 10; i++) {
        pb = GetPObj(); 
        pb->print();    // Вызываем нужную виртуальную функцию
        delete pb;      // Вызываем соответствующий деструктор
        std::cout << '\n';
    }

    return 0;
}
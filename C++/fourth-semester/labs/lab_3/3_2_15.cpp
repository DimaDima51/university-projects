#include <iostream>

class Base {
    public:
        void printA() {
            std::cout << "Метод A" << '\n';
        }

        void printB() {
            std::cout << "Метод B" << '\n';
        }

        void printC() {
            std::cout << "Метод C" << '\n';
        }

        void printD() {
            std::cout << "Метод D" << '\n';
        }

        void printE() {
            std::cout << "Метод E" << '\n';
        }
};

class Derived : private Base {
    public:
        using Base::printB;
        using Base::printD;
        
        void func1() {
            printA();
        }

        void func3() {
            printC();
        }

        void func5() {
            printD();
        }
};

int main() {
    Derived d;
    d.printB();
    d.printD();
    
    // Эти методы недоступны извне
    // d.method1();
    // d.method3();
    // d.method5();
    
    d.func1();
    d.func3();
    d.func5();
    
    return 0;
}
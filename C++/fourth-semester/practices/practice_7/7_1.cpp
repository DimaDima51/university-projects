#include <iostream>

// Базовый класс A
class A {
    public:
        A() {
            std::cout << "A constr" << '\n';  // Конструктор A
        }
        ~A() {
            std::cout << "A destr" << '\n';   // Деструктор A
        }
};

// Класс B наследуется от A с виртуальным наследованием
class B : virtual public A {
    public:
        B() {
            std::cout << "B constr" << '\n';  // Конструктор B
        }
        ~B() {
            std::cout << "B destr" << '\n';   // Деструктор B
        }
};

// Класс C наследуется от A с виртуальным наследованием
class C : virtual public A {
    public:
        C() {
            std::cout << "C constr" << '\n';  // Конструктор C
        }
        ~C() {
            std::cout << "C destr" << '\n';   // Деструктор C
        }
};

// Класс E наследуется от A с виртуальным наследованием
class E : virtual public A {
    public:
        E() {
            std::cout << "E constr" << '\n';  // Конструктор E
        }
        ~E() {
            std::cout << "E destr" << '\n';   // Деструктор E
        }
};

// Класс D наследуется от B, C, E (множественное наследование)
class D : public B, public C, public E {
    public:
        D() {
            std::cout << "D constr" << '\n';  // Конструктор D
        }
        ~D() {
            std::cout << "D destr" << '\n';   // Деструктор D
        }
};

// Класс F наследуется от D
class F : public D {
    public:
        F() {
            std::cout << "F constr" << '\n';  // Конструктор F
        }
        ~F() {
            std::cout << "F destr" << '\n';  // Деструктор F
        }
};

int main() {
    F obj1;
    
    return 0;
}
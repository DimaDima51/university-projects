#include <iostream>
#include <string>

// Базовый класс A
class A {
    int value;
    public:
        // Конструктор класса A
        A(int value) : value(value) {
            std::cout << "A constr value = " << value << '\n';
        }
        // Методы func1 и func2
        void func1() {
            std::cout << "A func1" << '\n';
        }
        void func2() {
            std::cout << "A func2" << '\n';
        }
};

// Класс B наследуется от A виртуально
class B : virtual public A {
    std::string str;

    public:
        B(int value, std::string str) : A(value), str(str) {
            std::cout << "B constr str = '" << str << "'" << '\n';
        }
};

// Класс C наследуется от A виртуально
class C : virtual public A {
    double value2;

    public:
        C(int value, double value2) : A(value), value2(value2) {
            std::cout << "C constr number = " << value2 << '\n';
        }
};

// Класс E наследуется от A виртуально
class E : virtual public A {
    char symb;

    public:
        E(int value, char symb) : A(value), symb(symb) {
            std::cout << "E constr symb = " << symb << '\n';
        }
};

// Класс D наследуется от B, C и E
class D : public B, public C, public E {
    bool flag;

    public:
        D(int value, std::string str, double value2, char symb, bool flag)
            : A(value), B(value, str), C(value, value2), E(value, symb), flag(flag) {
            std::cout << "D constr flag = " << flag << '\n';
        }
        
        // Устраняем неоднозначность
        using A::func1;
        using A::func2;
};

int main() {
    D d(5, "Hello", 3.14, 'h', false);

    // Вызываем методы func1 и func2 - благодаря using A::func1 и using A::func2
    d.func1();
    d.func2();
    
    return 0;
}
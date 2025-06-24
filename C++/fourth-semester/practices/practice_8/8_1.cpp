#include <iostream>
using namespace std;

class Base {
    public:
        // Виртуальная функция F - без параметров
        virtual int F() {
            cout << "Base:1\n";
            return 0;
        }

        // Перегрузка виртуальной функции - с параметром string
        virtual void F(string s) {
            cout << "Base:2\n";
        }
};

class Derived : public Base {
    public:
        // Новая функция F
        virtual int F(int t) {
            cout << "Derived:3\n"; 
            return 0;
        }
};


class AA : public Base {
    public:
        // Метод пытается переопределить F() из Base
        //virtual void F() {
        //    cout << "AA:4\n";
        //}

        // Переопределяем виртуальную функцию базового класса 
        virtual int F() {
            cout << "AA:4\n";
            return 0;
        }
};

int main() {
    Derived d; d.F(6);  // Derived F(int)
    
    Base* p_b = &d;
    p_b->F();           // Base F()
    p_b->F("hello");    // Base F(string)
    // p_b->F(8);       // Будет ошибка, т.к. в Base нет F(int)
    
    Derived* p_der = &d;
    p_der->F(9);        // Derived F(int)
    // p_der->F("hhh"); // F(string) скрыт в Derived
    // p_der->F();      // F() без параметров скрыт
    
    AA aa;
    aa.F();            // AA F()
    // aa.F("test");   // F(string) не видно т.к. он скрыт из-за F() в AA
    
    return 0;
}
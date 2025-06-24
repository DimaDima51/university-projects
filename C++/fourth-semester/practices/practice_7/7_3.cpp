#include <iostream>

class BaseA {
    public:
        virtual int F(double s) {
            std::cout << "BaseA::F() called with " << s << std::endl;
            return 1;
        }
};

class BaseB {
    public:
        virtual int F(double s) {
            std::cout << "BaseB::F() called with " << s << std::endl;
            return 2;
        }
};

// Промежуточный класс для BaseA
class BaseA2: public BaseA {
    public:
        virtual int FA(double s) = 0; // Чисто виртуальная функция
    private:
        int F(double s) override { // Переопределяем наследованную F
            return FA(s); // Перенаправляем вызов к FA
        }
};

// Промежуточный класс для BaseB
class BaseB2: public BaseB {
    public:
        virtual int FB(double s) = 0; // Чисто виртуальная функция
    private:
        int F(double s) override { // Переопределяем наследованную F
            return FB(s); // Перенаправляем вызов к FB
        }
};

// Финальный класс, реализующий оба интерфейса
class MyClass: public BaseA2, public BaseB2 {
    public:
        int FA(double s) override {
            std::cout << "MyClass::FA() called with " << s << std::endl;
            return 10; // Возвращаем значение для FA
        }

        int FB(double s) override {
            std::cout << "MyClass::FB() called with " << s << std::endl;
            return 20; // Возвращаем значение для FB
        }
};

int main() {
    BaseA *ca = new MyClass();
    BaseB *cb = new MyClass();

    int resultA = ca->F(8.2); // вызов FA() из MyClass
    std::cout << "ca->F(): " << resultA << std::endl;

    int resultB = cb->F(6.7); // вызов FB() из MyClass
    std::cout << "cb->F(): " << resultB << std::endl;

    delete ca;
    delete cb;
    return 0;
}
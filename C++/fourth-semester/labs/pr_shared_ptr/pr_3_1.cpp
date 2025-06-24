#include <iostream>
#include <memory>

class B;

class A {
    public:
        std::shared_ptr<B> ptrB;
        ~A() { std::cout << "A уничтожен\n"; }
};

class B {
    public:
        std::shared_ptr<A> ptrA;
        ~B() { std::cout << "B уничтожен\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->ptrB = b;
    b->ptrA = a;

    std::cout << "a: " << a.get() << '\n'; // адрес объекта A

    std::cout << "b: " << b.get() << '\n'; // адрес объекта B
}

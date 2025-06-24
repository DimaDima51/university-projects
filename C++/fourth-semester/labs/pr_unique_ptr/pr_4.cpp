#include <iostream>
#include <memory>
using namespace std;

class Base {};
class A : public Base {};

int main() {
    unique_ptr<Base> p;
    // p = new A();  // Ошибка

    p = unique_ptr<Base>(new A());
    p = make_unique<A>();  // A* -> Base* - допустимо
}

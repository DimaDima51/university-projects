#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int v) : value(v) { std::cout << "Конструктор\n"; }

    ~MyClass() { std::cout << "Деструктор\n"; }

    void print() const {
        std::cout << "Значение: " << value << '\n';
    }

private:
    int value;
};

int main() {
    int p = 15;

    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(p);
    std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>(p);

    std::shared_ptr<MyClass> ptr3 = ptr1;

    std::cout << "ptr1: " << ptr1.use_count() << '\n';
    std::cout << "ptr2: " << ptr2.use_count() << '\n';
    std::cout << "ptr3: " << ptr3.use_count() << '\n';

    ptr1->print();
    ptr2->print();
    ptr3->print();

    return 0;
}

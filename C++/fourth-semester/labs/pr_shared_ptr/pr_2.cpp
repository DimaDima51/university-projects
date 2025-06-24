#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass(int v) : value(v) {}

        ~MyClass() { }

        void print() {
            std::cout << "Значение: " << value << '\n';
        }

    private:
        int value;
};

int main() {
    int p = 15;

    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(p);
    std::shared_ptr<MyClass> ptr2 = ptr1; // ptr2 тоже владеет объектом

    std::cout << "Сколько shared_ptr владеют объектом: " << ptr1.use_count() << '\n'; // 2
    std::cout << "ptr2 единственный владелец? " << ptr2.unique() << '\n'; // false


    ptr2.reset(); 
    std::cout << "\nptr2 больше не владеет объектом\n";

    std::cout << "Сколько shared_ptr владеют объектом: " << ptr1.use_count() << '\n'; // 1
    std::cout << "ptr1 единственный владелец? " << ptr1.unique() << '\n'; // true

    // ptr3 будет владеть объектом, ptr1 станет 0, т.к. обменялись
    std::shared_ptr<MyClass> ptr3;
    ptr1.swap(ptr3);

    std::cout << "\nПосле swap между ptr1 и ptr3\n";
    std::cout << "ptr1: " << ptr1 << '\n';
    std::cout << "ptr3: " << ptr3 << '\n';

    if (ptr3) {
        ptr3->print();
    }

    return 0;
}

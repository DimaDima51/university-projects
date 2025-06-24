#include <iostream>
#include <list>
#include <memory>
using namespace std;

class MyInt {
private:
    int i;
public:
    MyInt(int par = 0) : i(par) { }
    friend ostream& operator<<(ostream& out, const MyInt& obj) {
        out << obj.i;
        return out;
    }
};

int main() {
    list<unique_ptr<MyInt>> m1;

    // Добавление элементов в список
    m1.push_back(make_unique<MyInt>(1));
    m1.push_back(make_unique<MyInt>(2));
    m1.push_back(make_unique<MyInt>(3));

    // Вывод значений
    for (const auto& ptr : m1) {
        if (ptr) {
            cout << *ptr << " ";
        }
    }
    cout << endl;

    return 0;
}

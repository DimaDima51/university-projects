#include <iostream>
#include <memory>
using namespace std;

class MyInt {
private:
    int i{ 0 };
public:
    MyInt(int par = 0) : i(par) { }
    friend ostream& operator<<(std::ostream& out, const MyInt& p) {
        out << p.i << endl;
        return out;
    }
};

void printInt(const MyInt* p) {
    if (p) cout << *p << endl;
}

int main() {
    unique_ptr<MyInt> p = make_unique<MyInt>(3);
    printInt(p.get());
    return 0;
}

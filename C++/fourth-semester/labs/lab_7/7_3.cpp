#include <iostream>
using namespace std;

int f(int p) {
    if (p < 0) throw 1;
    return 2 + p;
}

class MyType {
    int i;
    double d;
public:
    MyType(int ii, double dd) try : i(f(ii)), d(dd) {
        cout << "hello";
    }
    catch (...) {
        cout << "error";
        throw; // 1) Сохранить тип исключения
        throw runtime_error("Ошибка в MyType"); // 2) Сделать новое исключение
    }
};

int main() {
    MyType m(1, 2.3);
    
    return 0;
}
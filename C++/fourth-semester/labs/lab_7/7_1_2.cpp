#include <iostream>
using namespace std;

template <typename T>
class TD;

template <typename T>
ostream& operator<<(ostream &s, TD<T> &t);

template <typename T>
class TD {
    T x;
public:
    TD(const T &t) : x(t) {}

    friend ostream& operator<< <T>(ostream &s, TD<T> &t);

    friend TD<T> operator+(TD<T> a, TD<T> b) {
        TD<T> t = a;
        t.x += b.x;
        return t;
    }

    friend TD<T> operator+(TD<T> a, T b) {
        TD<T> t = a;
        t.x += b;
        return t;
    }
};

template <typename T>
ostream& operator<<(ostream &s, TD<T> &t) {
    return s << t.x;
}

int main() {
    TD<int> t(5), z(7);

    TD<int> y = z + 1;
    cout << y << '\n';

    return 0;
}

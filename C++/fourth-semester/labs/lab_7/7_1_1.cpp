#include <iostream>
using namespace std;

template <typename T>
class TD;

template <typename T>
    class TD {
        T x;
    public:
        TD(const T& t) : x(t) {} 

        friend ostream& operator<<(ostream& s, const TD<T>& t) {
            return s << t.x;
        }

        template <typename U>
        friend TD<U> operator+(TD<U> a, TD<U> b);
};

template <typename U>
TD<U> operator+(TD<U> a, TD<U> b) {
    TD<U> t = a;
    t.x += b.x;
    return t;
}

int main() {
    TD<int> t(5), z(7);
    TD<int> y = z + t;
    cout << y << endl; 

    return 0;
}

#include <iostream>
#include <cstddef>

using namespace std;

template<typename T, size_t N>
class MyArray {
    T arr[N];
    public:
        MyArray(const T &t = T()) {
            for(size_t i = 0; i < N; i++)
                arr[i] = t;
        }

        size_t getSize() const {
            return N;
        }

        const T& operator[](size_t i) const {
            if (i < N)
                return arr[i];
            throw "i > N!!!";
        }

        T& operator[](size_t i) {
            if (i < N)
                return arr[i];
            throw "i > N!!!";
        }

        template<typename T1, size_t N1>
        MyArray<T, N>& operator=(const MyArray<T1, N1>& obj) {
            size_t minSize = N < N1 ? N : N1;
            for (size_t i = 0; i < minSize; i++) {
                arr[i] = static_cast<T>(obj[i]);
            }

            return *this;
        }
};

int main() {
    MyArray<int, 10> a(1);
    MyArray<double, 5> b(3.14);

    a = b;

    for (size_t i = 0; i < a.getSize(); ++i)
        cout << "a[" << i << "] = " << a[i] << '\n';

    return 0;
}
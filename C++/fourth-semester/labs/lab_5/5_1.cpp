#include <iostream>

using namespace std;

template <typename T> 
void Swap(int &m, int &n, T*& a, T*& b) {
    T temp = a[m];
    a[m] = b[n];
    b[n] = temp;
}

int main() {
    int *x = new int[5]{1, 2, 3, 4, 5};
    int *y = new int[5]{6, 7, 8, 9, 10};

    for (int i = 0; i < 5; i++) {
        cout << x[i] << " ";
    }

    cout << '\n';

    for (int i = 0; i < 5; i++) {
        cout << y[i] << " ";
    }

    cout << '\n';

    int a, b;

    cout << "Введите индекс первого и второго массива: ";

    cin >> a >> b;

    Swap(a, b, x, y);

    cout << '\n';

    for (int i = 0; i < 5; i++) {
        cout << x[i] << " ";
    }

    cout << '\n';

    for (int i = 0; i < 5; i++) {
        cout << y[i] << " ";
    }

    delete[] x;
    delete[] y;

    return 0;
}
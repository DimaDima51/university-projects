#include <iostream>
using namespace std;

template <typename T, typename U>
void multiplyArrayElements(T* arr, int size, U multiplier) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= multiplier;
    }
}

int main() {
    int intArr[5] = {1, 2, 3, 4, 5};
    double doubleArr[3] = {1.1, 2.2, 4.0};

    for (int i = 0; i < 5; i++)
        cout << intArr[i] << " ";

    cout << '\n';
    
    for (int i = 0; i < 3; i++)
        cout << doubleArr[i] << " ";

    cout << '\n';

    multiplyArrayElements(intArr, 5, 3);
    multiplyArrayElements(doubleArr, 3, 0.5);

    for (int i = 0; i < 5; i++)
        cout << intArr[i] << " ";

    cout << '\n';

    for (int i = 0; i < 3; i++)
        cout << doubleArr[i] << " ";

    cout << '\n';

    return 0;
}
